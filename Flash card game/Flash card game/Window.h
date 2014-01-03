#pragma once
#include "SDL.h"
#include <fstream>
#include <iostream>
#include <string>
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
//Our window
using namespace std;
class Window
{
private:
	//Whether the window is windowed or not
	bool windowed;

	//Whether the window is fine
	bool windowOK;
public:

	Window();

	SDL_Surface *screen = NULL;

	//Constructor
	Window(SDL_Event gevent,SDL_Surface *see);

	//Handle window events
	void handle_events(SDL_Event *gevent);

	//Turn fullscreen on/off
	void toggle_fullscreen();

	//Check if anything's wrong with the window
	bool error();


};
