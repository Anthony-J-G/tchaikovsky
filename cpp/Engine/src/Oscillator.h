#pragma once

#include <vector>

#define SAMPLE_RATE 96000
#define BIT_DEPTH 16

#ifndef TCHAI_ASSERT
#include <assert.h>
#define TCHAI_ASSERT(_EXP, _MSG)	assert((_EXP) && _MSG) // Assertion Macro
#endif


namespace tchai {
	namespace core {

		enum class AmplitudeType {
			ConstantB=0,
			RSigmoid,
			GBubbles
		};


		enum class OscillatorType {
			Sinusoidal,
		};


		// Amplitude Functions	
		class Amplitude {
		public:
			Amplitude(AmplitudeType type, std::vector<double> Hyperparams);
			~Amplitude();

			double ConstantBreadth(int t);
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
			Oscillator(OscillatorType type, std::vector<double> Hyperparams);
			~Oscillator();

			double Sinusoid(int t);

		private:
			std::vector<double> Parameters;

		};

	}


}