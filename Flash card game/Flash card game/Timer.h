#pragma once
#include "Timer.h"
#include "SDL.h"
#include <fstream>
#include <iostream>
#include <string>
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
//The timer
class Timer
{
private:
	//The clock time when the timer started
	int startTicks;

	//The ticks stored when the timer was paused
	int pausedTicks;

	//The timer status
	bool paused;
	bool started;

public:
	//Initializes variables
	Timer();

	//The various clock actions
	void start();
	void stop();
	void pause();
	void unpause();

	//Gets the timer's time
	int get_ticks();

	//Checks the status of the timer
	bool is_started();
	bool is_paused();
};


