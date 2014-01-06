#include "Controller.h"


Controller::Controller()
{
}


Controller::~Controller()
{
}


Controller::Controller(SDL_Event* event)
{
	for (int i = 0; i < 322;i++){
		keys[i] = false;
	}
	events = event;
	mouseX = 0;
	mouseY = 0;
	activeX = 0;
	activeY = 0;
	bool clicked = false;
	bool clickedR = false;
}

void Controller::handleInput() 
{
	if (keys[SDLK_RIGHT]){ up = true; }
	if (keys[SDLK_LEFT]){ down = true; }
	if (keys[SDLK_UP]){ left = true; }
	if (keys[SDLK_DOWN]){ right = true; }
	if (keys[SDLK_w]){ b1 = true; }
	if (keys[SDLK_a]){ b2 = true; }
	if (keys[SDLK_s]){ b3 = true; }
	if (keys[SDLK_d]){ b4 = true; }
}

void Controller::update() {

	SDL_PumpEvents();
	if (SDL_GetMouseState(&mouseX, &mouseY))
	{
		clicked = false;
		clickedR = false;
	}
	if (SDL_GetMouseState(&mouseX, &mouseY)&SDL_BUTTON(1))
	{
		activeX = mouseX;
		activeY = mouseY;
	}
	if (SDL_GetMouseState(&mouseX, &mouseY)&SDL_BUTTON(1))
	{
		activeX = mouseX;
		activeY = mouseY;
	}

	if (SDL_PollEvent(events)){
		// message processing loop
		while (SDL_PollEvent(events))
		{
			// check for messages
			switch (events->type) {
				//check for mouse button press

				// exit if the window is closed
			case SDL_QUIT:
				quit = true; // set game state to done,(do what you want here)
				break;
				// check for keypresses
			case SDL_KEYDOWN:
				keys[events->key.keysym.sym] = true;
				break;
			case SDL_KEYUP:
				keys[events->key.keysym.sym] = false;
				break;
			default:
				break;

			}
			

		} // end of message processing


	}

}

int Controller::getMX() 
{
	return mouseX;
}

int Controller::getMY()
{
	return mouseY;
}

int Controller::getAX()
{
	return activeX;
}

int Controller::getAY()
{
	return activeY;
}