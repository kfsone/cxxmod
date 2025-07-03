// Simple greetings library.

#include "greet.h"

#include <cstdio>


// The use of a namespace that does not align with the library or
// module name is done for demonstrative purposes only. Ideally,
// you should try to align the names.
namespace greets
{


// ----------------------------------------------------------------------------
//! @brief greet prints hello to the specified name.
//! @param name   C-String representation of the name you want greeted.
//! @return none
//
void greet(const char* name)
{
	printf("Hello, %s!\n", name);
}


}  // endnamespace greets
