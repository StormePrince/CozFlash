#include "Window.h"
using namespace std;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 640;
const int SCREEN_BPP = 32;

Window::Window()
{}

Window::Window(SDL_Event gevent,SDL_Surface *see)
{
	//Set up the screen
	screen = see;

	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
	//If there's an error
	if (screen == NULL)
	{
		windowOK = false;
		return;
	}
	else
	{
		windowOK = true;
	}

	//Set the window caption
	SDL_WM_SetCaption("Window Event Test", NULL);

	//Set window flag
	windowed = true;
}

void Window::handle_events(SDL_Event *gevent)
{
	//If there's something wrong with the window
	if (windowOK == false)
	{
		return;
	}

	//If the window resized
	if (gevent->type == SDL_VIDEORESIZE)
	{
		//Resize the screen
		screen = SDL_SetVideoMode(gevent->resize.w, gevent->resize.h, SCREEN_BPP, SDL_SWSURFACE | SDL_RESIZABLE);

		//If there's an error
		if (screen == NULL)
		{
			windowOK = false;
			return;
		}
	}
	//If enter was pressed
	else if ((gevent->type == SDL_KEYDOWN) && (gevent->key.keysym.sym == SDLK_RETURN))
	{
		//Turn fullscreen on/off
		toggle_fullscreen();
	}
	//If the window focus changed
	else if (gevent->type == SDL_ACTIVEEVENT)
	{
		//If the window was iconified or restored
		if (gevent->active.state & SDL_APPACTIVE)
		{
			//If the application is no longer active
			if (gevent->active.gain == 0)
			{
				SDL_WM_SetCaption("Window Event Test: Iconified", NULL);
			}
			else
			{
				SDL_WM_SetCaption("Window Event Test", NULL);
			}
		}
		//If something happened to the keyboard focus
		else if (gevent->active.state & SDL_APPINPUTFOCUS)
		{
			//If the application lost keyboard focus
			if (gevent->active.gain == 0)
			{
				SDL_WM_SetCaption("Window Event Test: Keyboard focus lost", NULL);
			}
			else
			{
				SDL_WM_SetCaption("Window Event Test", NULL);
			}
		}
		//If something happened to the mouse focus
		else if (gevent->active.state & SDL_APPMOUSEFOCUS)
		{
			//If the application lost mouse focus
			if (gevent->active.gain == 0)
			{
				SDL_WM_SetCaption("Window Event Test: Mouse Focus Lost", NULL);
			}
			else
			{
				SDL_WM_SetCaption("Window Event Test", NULL);
			}
		}
	}
	//If the window's screen has been altered
	else if (gevent->type == SDL_VIDEOEXPOSE)
	{
		//Update the screen
		if (SDL_Flip(screen) == -1)
		{
			//If there's an error
			windowOK = false;
			return;
		}
	}
}

void Window::toggle_fullscreen()
{
	//If the screen is windowed
	if (windowed == true)
	{
		//Set the screen to fullscreen
		screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE | SDL_RESIZABLE | SDL_FULLSCREEN);

		//If there's an error
		if (screen == NULL)
		{
			windowOK = false;
			return;
		}

		//Set the window state flag
		windowed = false;
	}
	//If the screen is fullscreen
	else if (windowed == false)
	{
		//Window the screen
		screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE | SDL_RESIZABLE);

		//If there's an error
		if (screen == NULL)
		{
			windowOK = false;
			return;
		}

		//Set the window state flag
		windowed = true;
	}
}

bool Window::error()
{
	return !windowOK;
}

