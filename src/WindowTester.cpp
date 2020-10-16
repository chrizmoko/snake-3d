// WindowTester.cpp
//
// Implementation of WindowTester.hpp.

#include "WindowTester.hpp"
#include <SDL2/SDL.h>
#include <iostream>



WindowTester::run()
{
	int result = SDL_Init(SDL_INIT_VIDEO);
	if (result != 0)
	{
		SDL_Log("Unable to initialize SDL2: %s", SDL_GetError());
		return 1;
	}

	std::cout << "SDL2 has successfully been initialized." << std::endl;

	SDL_Window* w = SDL_CreateWindow("Window test", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_RESIZABLE);
	
	// In milliseconds
	SDL_Delay(5 * 1000);

	SDL_DestroyWindow(w);

	SDL_Quit();

	std::cout << "SDL2 has successfully quit." << std::endl;


	return 0;
}