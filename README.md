C++20/CMake Module Transition Demo
----------------------------------

Simple demonstration of transitioning a project from headers to modules by using 'export import'
and how to set this up in CMake.

Does not attempt to demonstrate stand-alone module use.

This approach will only get you so far - but it will give you a beachhead from which to plan
and build out your module transition on multi-target projects.

The short term build-time gains will probably buy you the development time you need to actually
do the transition properly :)


-- Oliver "kfsone" Smith, July 3 2025


Naming
------

I used disparate names _to demonstrate_ the naming independence. See main.cpp for
why this is a A Bad Idea(SM) and YMMV.

- Library:
    greet
- Namespace:
    greets
- Module name:
    greeting

In practice you probably want these to be similar or easily related.


Files
-----

- greet.h
    The old header-style definition of the Api
- greet.cpp
    Implements greets::greet()
- greet.ixx
    C++20 interface definition file of the lazy/modular transition type; that is,
    I'm not really using module definitions here, I'm just exporting the header.
- main.cpp
    Simple consume for the greet library that uses it to print "Hello, World!"
    
