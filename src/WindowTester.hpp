// WindowTester.hpp
//
// A basic driver class to get SDL2 initialized and setup. This should create
// the window of the application.

#ifndef WINDOWTESTER_HPP
#define WINDOWTESTER_HPP



class WindowTester
{
public:
	// Run() initializes and runs the program contained inside the method. The
	// method exits and returns 1 if an error has occurrd, otherwise 0 is
	// returned.
	int run();
};



#endif