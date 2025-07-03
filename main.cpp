#ifndef USE_MODULES

# include "greet.h"

#else

import "greeting";

#endif


int main()
{
	// Note that we don't use the module name here, instead we use
	// the namespace that was used to export greet within the module.
	greets::greet("World");

	// greeting::greet("The End");	// uncomment to make your compiler cry
}
