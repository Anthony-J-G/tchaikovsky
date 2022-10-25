In order to generate a sound, there must first be a waveform representation. Different musical instruments use different kinds of waveform representations and thus it is appropriate to support each of these different forms.

At the basic level, to create these waveforms, you need both an amplitude function that controls the volume as well as an oscillator that controls the shape of the waveform. The amplitude function is handled through the use of the *Amplitude* class, while the actual oscillator is handled by the *Oscillator* class. 

The default constructor for the *Amplitude* class takes 2 arguments, an integer/enum reference that determines what amplitude function the class will use in the render as well as the hyper parameters to be utilized for that object.

```
// Example

int main() {
	// Create a Sigmoid Amplitude Function
	tchai::core::Amplitude A(PSigmoid, {2.0f, 3.0f, 6400.0f, 0.1f});

	// Create a Sinusoidal Waveform Function
	double sample_rate = 96000;
	tchai::core::Oscillator W(
		SinusoidalWF, // Waveform Shape Type
		{2.0f, 440.0f, 0.0f, sample_rate} // Hyper Parameters
	);

	double t = 1.0f; // Timestamp in seconds
	double sample = W.render(t); // Rendered Sound Sample
}


```