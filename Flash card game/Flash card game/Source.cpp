#include "SDL.h"
#include <fstream>
#include <iostream>
#include <string>
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "Window.h"

using namespace std;

//Screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;
SDL_Surface *gScreen;



//The event structure
SDL_Event event;
Window gamewindow;

bool init()
{
	//Initialize all SDL subsystems
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return false;
	}

	//Set up the screen
	gamewindow = Window(event,gScreen);

	//If there was an error in setting up the screen
	if (gamewindow.screen == NULL)
	{
		return false;
	}

	//Initialize SDL_ttf
	if (TTF_Init() == -1)
	{
		return false;
	}

	//Initialize SDL_mixer
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return false;
	}

	//Set the window caption
	SDL_WM_SetCaption("Monitor Music", NULL);

	//If everything initialized fine
	return true;
}

SDL_Surface *load_image(std::string filename)
{
	//The image that's loaded
	SDL_Surface* loadedImage = NULL;

	//The optimized surface that will be used
	SDL_Surface* optimizedImage = NULL;

	//Load the image
	loadedImage = IMG_Load(filename.c_str());

	//If the image loaded
	if (loadedImage != NULL)
	{
		//Create an optimized surface
		optimizedImage = SDL_DisplayFormat(loadedImage);

		//Free the old surface
		SDL_FreeSurface(loadedImage);

		//If the surface was optimized
		if (optimizedImage != NULL)
		{
			//Color key surface
			SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB(optimizedImage->format, 0, 0xFF, 0xFF));
		}
	}

	//Return the optimized surface
	return optimizedImage;
}

int main(int argc, char* args[])
{
	init();
	return 0;
}
