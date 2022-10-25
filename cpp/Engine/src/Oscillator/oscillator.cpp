#include "../Oscillator.h"






double std_wav(int t, std::vector<double> hyperparams) {

	try {
		if (hyperparams.size() != 3) {
			throw hyperparams.size();
		}
	}
	catch (int e) {
		std::cout << "An Exception has occurred. Parameter 'hyperparams' invalid size " << e << ". Size 3 expected.";
	}

	double func;
	double theta;
	double c, f, omega;
		
	c = hyperparams[0];
	f = hyperparams[1];
	omega = hyperparams[2];

	theta = (c * M_PI * f * t) / SAMPLE_RATE;
	theta += omega;

	func = sin(theta);

	return func;
}



// Oscillator Class Function Definitions
namespace tchai {
	namespace core {

		Oscillator::Oscillator(OscillatorType type_, std::vector<double> Hyperparams_, Amplitude amp_func_) {
			Parameters = Hyperparams_;
			wave_type = type_;
			amp_func = amp_func_;

		}


		Oscillator::~Oscillator() {
		}


		double Oscillator::Sinusoid(int t) {
			double func;
			double theta;
			double c, f, omega;

			c = Parameters[0];
			f = Parameters[1];
			omega = Parameters[2];

			theta = (c * M_PI * f * t) / SAMPLE_RATE;
			theta += omega;

			func = sin(theta);

			return func;

		}

		OscillatorType Oscillator::GetWaveType() {
			return wave_type;
		}


		double Oscillator::Render(int t) {

			double wave = 0.0f;
			double amplitude = amp_func.Render(t);

			return amplitude * wave;
		}


	}
}




