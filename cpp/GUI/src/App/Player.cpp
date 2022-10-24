// Include Statements

// Self Header Files
#include "../App.h"






void tchai::GUI::BasicPlayer() {
	
	SoundDevice* main_snd_dev = SoundDevice::get();

	static bool is_playing = 0;
	static bool is_paused = 0;
	static int start_time = 0;
	static int time = 0;
	static float progress = 0.0f, progress_dir = 1.0f;

	ImGui::Begin("Player");
	if (!is_playing && ImGui::Button("Play")) {
		is_playing = 1;
		is_paused = 0;

	}
	if (is_playing && ImGui::Button("Pause")) {
		is_playing = 0;
		is_paused = 1;

	}
	if (ImGui::IsItemHovered()) {
		ImGui::SetTooltip("Begin Playback");

	}
	ImGui::SameLine(0.0f, 0.0f);
	if (ImGui::IsItemHovered()) {
		ImGui::SetTooltip("Pause Playback");

	}
	ImGui::SameLine(0.0f, 0.0f);
	if (ImGui::Button("Stop")) {
		is_playing = 0;
		is_paused = 0;
		progress = 0.0f;
		progress_dir = 1.0f;

	}
	if (ImGui::IsItemHovered()) {
		ImGui::SetTooltip("End Playback");

	}

	// Animate a simple progress bar
	if (is_playing && !is_paused) {
		progress += progress_dir * 0.4f * ImGui::GetIO().DeltaTime;
		if (progress >= +1.1f) { progress = +1.1f; progress_dir *= -1.0f; }
		if (progress <= -0.1f) { progress = -0.1f; progress_dir *= -1.0f; }
	}

	// Typically we would use ImVec2(-1.0f,0.0f) or ImVec2(-FLT_MIN,0.0f) to use all available width,
	// or ImVec2(width,0.0f) for a specified width. ImVec2(0.0f,0.0f) uses ItemWidth.
	ImGui::ProgressBar(progress, ImVec2(0.0f, 0.0f));
	ImGui::SameLine(0.0f, ImGui::GetStyle().ItemInnerSpacing.x);
	ImGui::Text("Progress Bar");	
		
	ImGui::End();

}