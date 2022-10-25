___

```
namespace tchai {
// ...

namespace GUI {
	// ...

}

}
```


The <i>GUI</i> namespace is used for all of the functionality to be used in the GUI application.

The segregation to a different namespace from the <i>core</i> implementation is to denote that it is meant to be an extension of the main project, and not core to its inner functionality. The GUI namespace additionally has a heavy dependency on many of the functions in the other namespaces.

## Non-Project Dependencies
- JsonCpp
- OpenAL Soft
- Libsndfile
- 