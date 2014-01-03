#pragma once
#include "simplefuncs.h"


Simplefuncs::Simplefuncs(SDL_Renderer* render)
{
		rend = render;
}

Simplefuncs::Simplefuncs()
{
}
Simplefuncs::~Simplefuncs()
{
}

SDL_Texture* Simplefuncs::Load(char* File)
{
	SDL_Texture* temp = IMG_LoadTexture(rend, File);
	if (temp=NULL)
	{
		test();
	}
	return temp;
}

void Simplefuncs::test(){
	SDL_DestroyRenderer(rend);
	rend = NULL;
}

bool Simplefuncs::Draw(SDL_Texture* src, int x, int y, int xd, int yd, int width, int height, int widthd, int heightd)
{
	if (src == NULL ) {
		return false;

	}

	SDL_Rect destR;

	destR.x = xd;
	destR.y = yd;
	destR.w = widthd;
	destR.h = heightd;
	SDL_Rect srcR;

	srcR.x = x;
	srcR.y = y;
	srcR.w = width;
	srcR.h = height;
	SDL_RenderCopy(rend, src, &srcR, &destR);

	return true;
}

bool Simplefuncs::Drawtext(string text,int x, int y, int size, int fR, int fG, int fB, int bR, int bG, int bB)
{
	// Open our font and set its size to the given parameter //
	TTF_Font* font = TTF_OpenFont("arial.ttf", size);

	SDL_Color foreground = { fR, fG, fB };   // text color 
	SDL_Color background = { bR, bG, bB };  // color of what's behind the text 

	// This renders our text to a temporary surface. There //
	// are other text functions, but this one looks nicer. //
	SDL_Surface* temp = TTF_RenderText_Shaded(font, text.c_str(), foreground, background);

	// A structure storing the destination of our text. //
	SDL_Rect destination = { x, y, 0, 0 };

	//create texture from temp
	SDL_Texture* texttexture = SDL_CreateTextureFromSurface(rend, temp);

	// Gets height and width of   texttexture and put it in w and h
	int w, h;
	SDL_QueryTexture(texttexture, NULL, NULL, &w, &h);

	// Blit the text surface to our window surface. //
	Draw(texttexture , 0,0,x,y,w,h,w,h);
	// Always free memory! //
	SDL_FreeSurface(temp);

	// Close the font. //
	TTF_CloseFont(font);

	return true;
}