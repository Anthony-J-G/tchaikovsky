#pragma once


// Custom Headers
#include "Oscillator.h"
#include "Testing.h"
#include "SoundBuffer.h"

// Standard Library Builtins
#include <iostream>
#include <cmath>
#include <string>

// External Dependencies
#include "imgui.h"
#include "implot.h"


// Preprocessor Directives
#define PI 3.14159265358979323846

#define PLAYER_CLAMP(V, MN, MX)     ((V) < (MN) ? (MN) : (V) > (MX) ? (MX) : (V))



namespace tchai {
	namespace GUI {

		void RenderUI();

		void SinusoidWaveBuilder();

		void CompoundWaveBuilder();

		void BasicPlayer();

		void Viewport();

		// void Dockable();
	
	
	
	}
}


