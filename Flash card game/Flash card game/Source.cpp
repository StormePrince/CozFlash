#pragma once
#include "base.h"
#include "sprite.h"


//Screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;
SDL_Window* window = NULL;

SDL_Renderer* renderer = NULL;


struct StateStruct
{
	void(*StatePointer)();
};

// Global data //
stack<StateStruct> g_StateStack;

//The event structure
SDL_Event* mainEvent = new SDL_Event();

bool init()
{
	//Initialize all SDL subsystems
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return false;
	}




	//Initialize SDL_mixer
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return false;
	}


	//If everything initialized fine
	return true;
}





int main(int argc, char* args[])
{
	
	init();
	bool quit = false;
	window = SDL_CreateWindow("My first RPG!", 100, 100, 600, 500, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	Simplefuncs pen = Simplefuncs(renderer);
	Sprite floozy = Sprite(renderer, 16, 16, 7);
	floozy.Load("data/Character/foo.png");
	floozy.setposx(300);
	floozy.setposy(300);
	SDL_Texture* test;
	test = pen.Load("Data\Character\foo.bmp");
	while (!quit && mainEvent->type != SDL_QUIT)
	{
		if (test = NULL){
			quit = true;
			pen.test();
		}
		SDL_PollEvent(mainEvent);
		SDL_RenderClear(renderer);
		floozy.nextFrame();
		if (floozy.getframe()>7)
		{
			floozy.setframe(0);
		}
		if (pen.Draw(test, 0, 0, 20, 20, 16, 16, 200, 200) == false)
		{
		}

		SDL_RenderPresent(renderer);
	}

	return 0;
}
