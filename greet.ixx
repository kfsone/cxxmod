// To demonstrate how things are independent, I'm giving the
// module a name that does not match the namespace.
export module greeting;

// Load the header file and export everything in it.
export import "greet.h";
