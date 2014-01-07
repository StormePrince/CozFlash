#include "button.h"


Button::Button(int w, int h, Sprite back,char* text)
{

	image = back;
	width = w;
	height = h;
	buttonText = text;
	collisionBox = Box(image.getPosx(), image.getPosx()+width, image.getPosy(), image.getPosy()+height);
}

Button::Button()
{
}


Button::~Button()
{
}

void Button::changeBox(int x, int y,int w,int h)
{
	image.setPosx(x);
	image.setPosy(y);
	collisionBox = Box(image.getPosx(), image.getPosx() + width, image.getPosy(), image.getPosy() + height);
}

bool Button::load(char* fontFile, char* back, int size, int r, int g, int b)
{

	SDL_Surface* temp = image.getPen()->saveTextSolid(buttonText, fontFile, size, r, g, b);
	SDL_Surface* temp2 = IMG_Load(back);
	SDL_SetColorKey(temp, SDL_TRUE, SDL_MapRGB(temp->format, 0xFF, 0, 0xFF));
	SDL_BlitSurface(temp, NULL, temp2, NULL);
	image.load(SDL_CreateTextureFromSurface(image.getPen()->getRend(),temp));
	return true;
}