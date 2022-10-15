// Include Statements

// Self Header Files
#include "../App.h"

// Custom Headers
#include "Oscillator.h"
#include "Testing.h"
#include "SoundDevice.h"

// Standard Library Builtins
#include <iostream>
#include <cmath>

// External Dependencies
#include "imgui.h"
#include "implot.h"


void tchai::GUI::ShowBasicPlayer() {
	
	SoundDevice* main_snd_dev = SoundDevice::get();


	static int clicked = 0;
	ImGui::Begin("Player");
	if (ImGui::Button("Play")) {
		clicked++;
	}
	if (ImGui::IsItemHovered()) {
		ImGui::SetTooltip("Play a song");
	}
	if (clicked & 1) {
		// tests::CheckPlayback();



	}
	
	
		
	ImGui::End();

}