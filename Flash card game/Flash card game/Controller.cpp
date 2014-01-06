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
}

void Controller::update() {

	SDL_GetMouseState(&mouseX, &mouseY);

	// message processing loop
	while (SDL_PollEvent(events)) {
			// check for messages
			switch (events->type) {
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
				//If the mouse moved
			default:
				break;
			}
		} // end of message processing
	
}
