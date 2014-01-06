#pragma once
#include "base.h";
#include "simplefuncs.h";
class Controller
{
public:
	Controller();
	~Controller();
	Controller(SDL_Event* event);
	bool keys[322];
	void update();
	int mouseX;
	int mouseY;
private:
	SDL_Event* events;
	bool quit;
	int activeX;
	int activeY;
	bool clicked;
};

