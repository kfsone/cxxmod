// Simple executable that says hello to "World".

// By default we'll be configured to use headers instead of modules.
// To enable module use, run the generate phase of cmake with -DUSE_MODULES=ON.
// In the CMakeLists this will also add a C++ level -DUSE_MODULES=1
#ifndef USE_MODULES
// Old way
#include "greet.h"

#else
// New way
import "greeting";

#endif


int main()
{
	// Note that we don't use the module name here, instead we use
	// the namespace that was used to export greet within the module.
	greets::greet("World");

	// greeting::greet("The End");	// uncomment to make your compiler cry
}
