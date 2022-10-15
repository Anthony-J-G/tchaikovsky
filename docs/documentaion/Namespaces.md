___



## Tchaikovsky
___
```
namespace tchai {
	// ...

}
```

This is the main namespace of the API. All parts of the project will fall under this namespace.


## Core
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


## Playback
___

```
namespace tchai {
// ...

namespace playback {
	// ...

}

}
```

The playback namespace is used for rendering the audio to the sound devices. All of the OpenAL interfacing is done through this namespace.


## Extension: Conductor
___

```
namespace tchai {
// ...

namespace conductor {
	// ...

}

}
```


The <i>extGUI</i> namespace is used for all of the functionality to be used in the GUI application. The segregation to a different namespace from the <i>core</i> implementation is to denote that it is meant to be an extension of the main project, and not core to its inner functionality.


## Extension: GUI
___

```
namespace tchai {
// ...

namespace GUI {
	void SinusoidalBuilderWindow();
	// ...

}

}
```


The <i>extGUI</i> namespace is used for all of the functionality to be used in the GUI application. The segregation to a different namespace from the <i>core</i> implementation is to denote that it is meant to be an extension of the main project, and not core to its inner functionality.




















tags: #Tchaikovsky