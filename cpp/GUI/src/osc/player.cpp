#include "../Player.h"

#include "imgui.h"


void tchai::GUI::ShowBasicPlayer() {
	ImGui::Begin("Player");
	ImGui::Button("Button");
	if (ImGui::IsItemHovered()) {
		ImGui::SetTooltip("I am a tooltip");
	}
		
	ImGui::End();

}