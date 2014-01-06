#pragma once
#include "sprite.h"
#include "controller.h"

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

// stack for holding gamestate //
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
	
	//Initialize SDL TTF
	TTF_Init();


	//Initialize SDL_mixer
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return false;
	}


	//If everything initialized fine
	return true;
}
bool endGame()
{
	SDL_Quit();
	TTF_Quit();
	return true;
}




int main(int argc, char* args[])
{
	init();
	bool quit = false;
	window = SDL_CreateWindow("My first RPG!", 100, 100, WINDOW_WIDTH,WINDOW_HEIGHT,  SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	Simplefuncs pen = Simplefuncs(renderer);
	Controller input = Controller(mainEvent);

	SDL_Texture* testb = NULL;
	testb = LOAD(renderer, "Data/Character/foo.png");

	Sprite* floozy = new Sprite(&pen,16,16,7,0);

	floozy->load(testb);
	floozy->setPosx(22);
	floozy->setPosy(22);

	while (!quit && mainEvent->type != SDL_QUIT)
	{
		SDL_PollEvent(mainEvent);
		SDL_RenderClear(renderer);
		input.update();
		floozy->setPosx(input.getAX());
		floozy->setPosy(input.getAY());
		floozy->animateCenter(1,6,64,64);
		SDL_RenderPresent(renderer);
		SDL_Delay(25);
	}
	
	endGame();
	return 0;
}