___

```
namespace tchai {
// ...

namespace core {
	enum OscType{Sine};
	double SineWave(
		float coefficient, float freq, double sample_rate, float phase
	);
	class Amplitude(int type, std::vector<double> params);
	class Oscillator(int type);
	// ...

}
// ...

}
```

The core namespace deals with generating <i>Note</i> objects