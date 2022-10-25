#include "../App.h"



void tchai::GUI::Viewport(std::vector<double> * test) {

    const int n = 1001;
    const int m = 11;

    static float X1[n], Y1[n]; // Wave Function g(x)
    static double X2[m], Y2[m]; // Amplitude Function A(x)
    double peak_ampl = 1;


    ImGui::Begin("Wave Viewport");


    for (int i = 0; i < test->size(); i++) {
        ImGui::Text(std::to_string(test->at(i)).c_str());
    }
/*
    // Calculate Wave Function
    for (int i = 0; i < n; ++i) {
        float x = (float)i * 0.001f;

        float dt = (float)ImGui::GetTime();
        float c = coefficient * pi;
        float t = (x + dt / 10);
        float s = Sampling[sample_rate];
        float theta = (c / s) * frequency * t;

        float y = AmpFunc.Render(x) * sinf(theta + phase);

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
*/

    ImGui::End();

}