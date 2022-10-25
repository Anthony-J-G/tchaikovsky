// Include Statements

// Self Header Files
#include "../App.h"




void tchai::GUI::SinusoidWaveBuilder(std::vector<tchai::core::Oscillator> * Waves) {

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
    
    
    // Waveform Shape ImGui Widgets
    ImGui::Text("Waveform Shape Parameters:");
	ImGui::InputFloat("Scale Coefficient",	&coefficient, 1.0f, 1.0f, "%.3f");
	ImGui::InputFloat("Frequency (Hz)",		&frequency, 10.0f, 1.0f, "%.3f");
	ImGui::InputFloat("Wave Phase",			&phase, 0.5f, 1.0f, "%.3f");
    ImGui::Combo("Sample Rate (kHz)",       &sample_rate, Items, IM_ARRAYSIZE(Items));
    ImGui::Separator();

    // Amplitude Function Parameter Variables
    const core::AmplitudeType FuncTypes[] = {
        core::AmplitudeType::ConstantH, 
        core::AmplitudeType::RSigmoid,
        core::AmplitudeType::GBubbles,
    };
    const char* Items2[] = { "Constant Heights", "Reversed Sigmoid", "Gaussian Bubbles" };
    static int index = 0;
    static double AmpParams[] = {0.0f, 0.0f, 0.0f, 0.0f};

    static core::Amplitude AmpFunc(core::AmplitudeType::ConstantH, {1});

    ImGui::Text("Amplitude Parameters:");
    ImGui::Combo("Amplitude Function Type", &index, Items2, IM_ARRAYSIZE(Items2));
    // Set Amplitude Function Type/Options
    switch (FuncTypes[index]) {
        // If Constant Heights Amplitude is selected
        case core::AmplitudeType::ConstantH:
            ImGui::InputDouble("Amplitude", &AmpParams[0], 0.5f, 1.0f, "%.3f");
            AmpFunc = core::Amplitude(
                core::AmplitudeType::ConstantH,
                { AmpParams[0] }
            );
            break;

        // If Reversed Sigmoid Amplitude is selected
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

        // If Gaussian Bubbles Amplitude is selected
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


    static int clicked = 0;
    static float time = 0;
    static core::Oscillator Osc(core::OscillatorType::Sinusoidal, {}, AmpFunc);

    if (ImGui::Button("Add To Wave Stack")) {
        clicked++;

    }
    if (clicked & 1) {
        Waves->push_back(Osc);                
        clicked = 0;
        // GUI::BasicPlayer();

    }

	ImGui::End();

}


void tchai::GUI::CompoundWaveBuilder() {

}