#pragma once

#define _USE_MATH_DEFINES

#include <vector>
#include <math.h>
#include <stdio.h>
#include <iostream>

#define SAMPLE_RATE 96000
#define BIT_DEPTH 16

#ifndef TCHAI_ASSERT
#include <assert.h>
#define TCHAI_ASSERT(_EXP, _MSG)	assert((_EXP) && _MSG) // Assertion Macro
#endif


namespace tchai {
	namespace core {

		enum class AmplitudeType {
			ConstantH	= 0,
			RSigmoid	= 1 << 0,
			GBubbles	= 1 << 1
		};


		enum class OscillatorType {
			Sinusoidal	= 0,
		};


		// Amplitude Functions	
		class Amplitude {
		public:
			Amplitude();
			Amplitude(AmplitudeType type, std::vector<double> Hyperparams);
			~Amplitude();

			double ConstantHeights(int t);
			double ReversedSigmoid(int t); // TODO
			double GaussianBubbles(int t); // TODO

			double Render(int t);

		private:
			std::vector<double> Parameters;
			AmplitudeType ampfunc;

		};


		// Waveform Functions
		class Oscillator {
		public:
			Oscillator(OscillatorType type_, std::vector<double> Hyperparams_, Amplitude amp_func_);
			~Oscillator();

			double Sinusoid(int t);

			double Render(int t);

			OscillatorType GetWaveType();

		private:
			std::vector<double> Parameters;
			OscillatorType wave_type;
			Amplitude amp_func;

		};

	}


}