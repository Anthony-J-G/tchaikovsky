#include "../Oscillator.h"

#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <iostream>



// Amplitude Class Function Definitions
namespace tchai {
	namespace core {

		Amplitude::Amplitude(AmplitudeType amp_type, std::vector<double> Hyperparams) {
			Parameters = Hyperparams;

			// Hyper Parameter Assertions
			if (amp_type == AmplitudeType::ConstantB) { TCHAI_ASSERT(Parameters.size() == 1, "Malformed parameters, ensure that when using 'ConstantB' type amplitude function that the total number of parameters is equal to 1"); } // Assert that the number of hyperparameters is 1
			if (amp_type == AmplitudeType::RSigmoid) { TCHAI_ASSERT(Parameters.size() == 4, "Malformed parameters, ensure that when using 'RSigmoid' type amplitudefunction that the total number of parameters is equal to 4"); } // Assert that the number of hyperparameters is 4
			if (amp_type == AmplitudeType::GBubbles) { TCHAI_ASSERT(Parameters.size() == 4, "Malformed parameters, ensure that when using 'GBubbles' type amplitude function that the total number of parameters is equal to 4"); } // Assert that the number of hyperparameters is 4

			ampfunc = amp_type;

		}

		Amplitude::~Amplitude() {

		}


		double Amplitude::ConstantBreadth(int t) {
			double A = Parameters[0];
			return A;
		}


		double Amplitude::ReversedSigmoid(int t) {
			double A;
			double exponent;
			double a, b, c, d;

			a = Parameters[0];
			b = Parameters[1];
			c = Parameters[2];
			d = Parameters[3];

			exponent = pow(M_E, (t / c));
			A = (a / (b + exponent)) + d;

			return A;
		}


		double Amplitude::GaussianBubbles(int t) {
			double A;
			double exponent;
			double coefficient;
			double a, b, mu, sigma;

			a = Parameters[0];
			b = Parameters[1];
			mu = Parameters[2];
			sigma = Parameters[3];

			coefficient = a / (sigma * sqrt(2 * M_PI));
			exponent = pow(M_E, -0.5 * pow((t - mu) / sigma, 2));
			A = coefficient * exponent + b;

			return A;

		}

		double Amplitude::Render(int t) {
			switch (ampfunc) {
				case AmplitudeType::ConstantB:
					return Amplitude::ConstantBreadth(t);

				case AmplitudeType::RSigmoid:
					return Amplitude::ReversedSigmoid(t);

				case AmplitudeType::GBubbles:
					return Amplitude::GaussianBubbles(t);

			}
			
			return 0.0f;

		}

	}
}




