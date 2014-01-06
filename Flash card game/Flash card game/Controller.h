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
	void handleInput();
	int getMX();
	int getMY();
	int getAX();
	int getAY();
	bool quit;
	bool left;
	bool right;
	bool up;
	bool down;
	bool b1;
	bool b2;
	bool b3;
	bool b4;
private:
	SDL_Event* events;
	int activeX;
	int activeY;
	bool clicked;
	bool clickedR;
	int mouseX;
	int mouseY;
};

