#pragma once
#include "sprite.h"
#include "controller.h"
#include "button.h"

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

	Sprite BW = Sprite(&pen, 32, 128, 1, 1);
	Button FINISH = Button(32,128,BW,"FINISH");
	FINISH.load("Data/Fonts/zrnic.ttf", "Data/interface/boxBW.png",33,200,12,12);

	while (!quit && mainEvent->type != SDL_QUIT)
	{
		SDL_PollEvent(mainEvent);
		SDL_RenderClear(renderer);
		input.update();
		FINISH.changeBox(300,300,32,128);
		FINISH.image.showCenter();

		SDL_RenderPresent(renderer);
		SDL_Delay(25);
	}
	
	endGame();
	return 0;
}