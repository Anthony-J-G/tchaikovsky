// Include Statements

// Self Header Files
#include "../App.h"

// Custom Headers
#include "Oscillator.h"
#include "Testing.h"

// Standard Library Builtins
#include <iostream>
#include <cmath>

// External Dependencies
#include "imgui.h"
#include "implot.h"

// Preprocessor Directives
#define PI 3.14159265358979323846



void tchai::GUI::SinusoidBuilderWindow() {

    using namespace tchai;

    const int n = 1001;
    const int m = 11;

	ImGui::Begin("Sinusoid Wave Builder");
    
    const float pi = 3.1415926535897;

    // Waveform Shape Parameter Variables
	static float coefficient = 2.0f;
	static float frequency = 440.0f;
	static float phase = 0.0f;
    const float Sampling[] = { 44.1f, 48.0f, 88.2f, 96.0f, 192.0f };
    const char* Items[] = { "44.1", "48.0", "88.2", "96.0", "192.0" };
    static int sample_rate = 0; // Represented by current index of 'sampling' 
    
    static float X1[n], Y1[n]; // Wave Function g(x)
    
    // Waveform Shape ImGui Widgets
    ImGui::Text("Waveform Shape Parameters:");
	ImGui::InputFloat("Scale Coefficient",	&coefficient, 1.0f, 1.0f, "%.3f");
	ImGui::InputFloat("Frequency (Hz)",		&frequency, 10.0f, 1.0f, "%.3f");
	ImGui::InputFloat("Wave Phase",			&phase, 0.5f, 1.0f, "%.3f");
    ImGui::Combo("Sample Rate (kHz)",       &sample_rate, Items, IM_ARRAYSIZE(Items));
    ImGui::Separator();

    // Amplitude Function Parameter Variables

    const core::AmplitudeType FuncTypes[] = {
        core::AmplitudeType::ConstantB, 
        core::AmplitudeType::RSigmoid,
        core::AmplitudeType::GBubbles,
    };
    const char* Items2[] = { "Constant Breadth", "Reversed Sigmoid", "Gaussian Bubbles" };
    static int index = 0;
    static double AmpParams[] = {0.0f, 0.0f, 0.0f, 0.0f};

    static core::Amplitude AmpFunc(core::AmplitudeType::ConstantB, {1});

    static double X2[m], Y2[m]; // Amplitude Function A(x)

    ImGui::Text("Amplitude Parameters:");
    ImGui::Combo("Amplitude Function Type", &index, Items2, IM_ARRAYSIZE(Items2));
    switch (FuncTypes[index]) {
        case core::AmplitudeType::ConstantB:
            ImGui::InputDouble("Amplitude", &AmpParams[0], 0.5f, 1.0f, "%.3f");
            AmpFunc = core::Amplitude(
                core::AmplitudeType::ConstantB,
                { AmpParams[0] }
            );
            break;

        case core::AmplitudeType::RSigmoid:
            ImGui::InputDouble("a", &AmpParams[0], 1.0f, 1.0f, "%.3f");
            ImGui::InputDouble("b", &AmpParams[1], 10.0f, 1.0f, "%.3f");
            ImGui::InputDouble("c", &AmpParams[2], 0.5f, 1.0f, "%.3f");
            ImGui::InputDouble("d", &AmpParams[3], 0.5f, 1.0f, "%.3f");

            AmpFunc = core::Amplitude(
                core::AmplitudeType::RSigmoid,
                { AmpParams[0], AmpParams[1], AmpParams[2], AmpParams[3] }
            );
            break;

        case tchai::core::AmplitudeType::GBubbles:
            ImGui::InputDouble("a",     &AmpParams[0], 1.0f, 1.0f, "%.3f");
            ImGui::InputDouble("b",     &AmpParams[1], 10.0f, 1.0f, "%.3f");
            ImGui::InputDouble("mu",    &AmpParams[2], 0.5f, 1.0f, "%.3f");
            ImGui::InputDouble("sigma", &AmpParams[3], 0.5f, 1.0f, "%.3f");

            AmpFunc = core::Amplitude(
                core::AmplitudeType::GBubbles,
                { AmpParams[0], AmpParams[1], AmpParams[2], AmpParams[3] }
            );
            break;

        default:
            break;
    }

    double peak_ampl = 1;
    // Calculate Wave Function
    for (int i = 0; i < n; ++i) {
        float x = (float)i * 0.001f;

        float dt = (float)ImGui::GetTime();
        float c = coefficient * pi;
        float t = (x + dt / 10);
        float s = Sampling[sample_rate];
        float theta = (c / s) * frequency * t;

        float y = AmpFunc.Render(x) * sinf( theta + phase );

        X1[i] = x;
        Y1[i] = y;

        if (y > peak_ampl) {
            peak_ampl = y;
        }
    }
    
    // Calculate Amplitude Function
    for (int i = 0; i < m; ++i) {
        double x = (double)i * 0.1f;
        double y = AmpFunc.Render(x);

        X2[i] = x;
        Y2[i] = y;
    }

    // Draw Graphs
    static ImPlotAxisFlags flags;
    flags |= ImPlotAxisFlags_Lock; // Set Flag to lock plot
    if (ImPlot::BeginPlot("Sine Waveform")) {
        ImPlot::SetupAxes("x", "y", flags, flags);
        ImPlot::SetupAxesLimits(0, X1[n - 1], -peak_ampl, peak_ampl);
        ImPlot::PlotLine("Wave Function g(x)", X1, Y1, n);
        ImPlot::SetNextMarkerStyle(ImPlotMarker_Circle);
        ImPlot::PlotLine("Amplitude Function A(x)", X2, Y2, m);
        
        ImPlot::EndPlot();
    }

    static int clicked = 0;
    static float time = 0;

    if (ImGui::Button("Play Sound")) {
        clicked++;

    }
    if (clicked & 1) {
        GUI::ShowBasicPlayer();

    }

	ImGui::End();

}