// Window.hpp
//
// A wrapper class for the SDL2 window struct and the corresponding C-style
// functions. This abstracts away some of the original functionality leaving
// the functionality needed for the program.

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL_video.h>
#include <queue>
#include "Renderer.hpp"



class Window
{
public:
	// Creates a window initialized from the provided dimensions and title. The
	// title of the window is a C-style string. An exception will be thrown if
	// the dimensions of the window are invalid.
	Window(const char* title, int width, int height);

	// Safely deallocates the window to prevent memory leaks.
	~Window() noexcept;

	// width() returns the width of the window.
	int width() const noexcept;

	// height() returns the height of the window.
	int height() const noexcept;

	// title() returns the title of the window as a C-style string. If the 
	// window does not have a title, then an empty string will be returned.
	const char* title() const;

	// setVisible() sets the visibility of the window. If true, then the window
	// will be shown, otherwise the window will be hidden if false.
	void setVisible(bool visibility);

	// isVisible() returns a boolean indicating if the window is visible.
	bool isVisible() const noexcept;

	// addRenderer() adds a renderer to the render queue at the given priority.
	// Higher value priorities will be drawn to the window first, then
	// succeeded by lower value priorities.
	void addRenderer(const Renderer& renderer, int priority);

	// removeAllRenderers() removes all the renderers from the rendering queue.
	void removeAllRenderers();

	// refresh() effectively calls the draw() method from the renderers in the
	// rendering queue. Renderers with higher value priorities will be called
	// before those with lower value priorities.
	void refresh();

private:
	SDL_Window* window_;
	bool visibility_;
	std::priority_queue<Renderer> render_queue_;
};



#endif