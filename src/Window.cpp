// Window.cpp
//
// Implementation of Window.hpp.

#include "Window.hpp"
#include <SDL2/SDL_video.h>
#include <SDL2/SDL.h>
#include <queue>
#include "Renderer.hpp"
#include "WindowException.hpp"



Window::Window(const char* title, int width, int height)
{
	if (SDL_WasInit(SDL_INIT_VIDEO) != SDL_INIT_VIDEO)
	{
		throw WindowException("SDL2 video system has not been initialized");
	}

	if (width < 0 || height < 0)
	{
		throw WindowException("Window dimensions must be non-negative values.");
	}

	window_ = SDL_CreateWindow(
		title,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
		SDL_WINDOW_HIDDEN | SDL_WINDOW_RESIZABLE
	);

	if (window_ == nullptr)
	{
		SDL_DestroyWindow(window_);
		throw WindowException(SDL_GetError());
	}

	visibility_ = false;}

Window::~Window()
{
	SDL_DestroyWindow(window_);
}

int Window::width() const noexcept
{
	int width;
	SDL_GetWindowSize(window_, &width, nullptr);
	return width;
}

int Window::height() const noexcept
{
	int height;
	SDL_GetWindowSize(window_, nullptr, &height);
	return height;
}

const char* Window::title() const
{
	return SDL_GetWindowTitle(window_);
}

void Window::setVisible(bool visibility)
{
	if (visibility)
	{
		SDL_ShowWindow(window_);
	}
	else
	{
		SDL_HideWindow(window_);
	}
	visibility_ = visibility;
}

bool Window::isVisible() const noexcept
{
	return visibility_;
}

void addRenderer(const Renderer& renderer, int priority)
{
	// TODO : Figure out how you should implement this.
}

void removeAllRenderers()
{
	// TODO : Figure out how you should implement this.
}

void refresh()
{
	// TODO : Figure out how you should implement this.
}