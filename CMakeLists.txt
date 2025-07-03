cmake_minimum_required (VERSION 3.31)  # 4.0 for best module support
# Demonstration project that will build a small greet program that
# uses its own library for printing greetings, and either imports
# the library as a module or includes it via header files.
#
# To build the header way:
#
#   cmake -S . -B build ; cmake --build build
# or
#   cmake -S . -B build -DUSE_MODULES=OFF ; cmake --build build
#
# To build the module way:
#
#   cmake -S . -B build -DUSE_MODULES=ON ; cmake --build build
#
# In the above "build" is my standard output/build directory, s/build/out/ if you will.
#
# You *may* need to help CMake identify which compiler/toolchain to
# use by selecting a Generator, see "CMake -G" for a list, if you're
# on Windows it will be near the top corresponding to the version of
# Visual Studio you have installed. Otherwise, I recommend Ninja.
#
#   cmake -G "Visual Studio 17 2022" -S . -B build ; cmake --build build


set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

option (USE_MODULES "Enable CXX module use" OFF)


project (greet LANGUAGES CXX)


# First, define something in a library that we can include or import,
# and we'll use the modular-modularization approach whereby we simply
# export everything in the header file(s).
add_library (
	greet

	greet.cpp

	greet.h
)
if (USE_MODULES)
  # Tell it about the module interface file(s). Note that the name of the target,
  # and the name of the interface files do not *have* to identify the name of the
  # module.
  target_sources (
		greet
		PUBLIC
			FILE_SET	cxx_modules
			TYPE 		CXX_MODULES
			FILES
				greet.ixx  # namespace: greets, .ixx defines module name as: greeting
  )
endif ()


# Define a consumer for the module, a simple executable.
# It will either #include the module headers or import them depending
# on whether you have set USE_MODULES or not.
add_executable (
	greeter

	main.cpp
)
# We still need to advise CMake of the linkage relationship
target_link_libraries (greeter PUBLIC greet)
if (MY_USE_MODULES)
  # Tell CMake to scan this project for imports before building it
  set_target_properties (greeter PROPERTIES CMAKE_CXX_SCAN_FOR_MODULES ON)
  # Tell the code it can use the module path.
  target_compile_definitions (greeter PUBLIC -DMY_MODULES=1)
endif ()
