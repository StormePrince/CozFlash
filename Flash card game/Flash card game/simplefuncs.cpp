#pragma once
#include "simplefuncs.h"


Simplefuncs::Simplefuncs(SDL_Renderer* render)
{
	rend = render;
	
}

void Simplefuncs::test(){
	SDL_DestroyRenderer(rend);
	rend = NULL;
}

Simplefuncs::Simplefuncs()
{
}
Simplefuncs::~Simplefuncs()
{
}

SDL_Renderer* Simplefuncs::getRend()
{
	return rend;
}


bool Simplefuncs::draw(SDL_Texture* src, int x, int y, int xd, int yd, int width, int height, int widthd, int heightd)
{
	if (src == NULL ) {
		throw std::runtime_error(SDL_GetError());
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

bool Simplefuncs::draw(SDL_Texture* src, int x, int y, int xd, int yd, int width, int height)
{
	if (src == NULL) {
		throw std::runtime_error(SDL_GetError());
		return false;
	}

	SDL_Rect destR;

	destR.x = xd;
	destR.y = yd;
	destR.w = width;
	destR.h = height;

	SDL_Rect srcR;

	srcR.x = x;
	srcR.y = y;
	srcR.w = width;
	srcR.h = height;
	SDL_RenderCopy(rend, src, &srcR, &destR);

	return true;
}

bool Simplefuncs::drawText(char* text, char* fontfile,int size, int x, int y,  int fR, int fG, int fB)
{
	// Open our font and set its size to the given parameter //
	TTF_Font* font = nullptr;
	font = TTF_OpenFont(fontfile,size);
	if (font == nullptr){
		throw std::runtime_error(TTF_GetError());
		return false;
	}

	SDL_Color textColor = { fR, fG, fB };   // text color 
	int w, h;
	SDL_Surface *temp;
	temp = TTF_RenderUTF8_Blended(font, text, textColor);
	SDL_Texture* message = SDL_CreateTextureFromSurface(rend, temp);
	SDL_QueryTexture(message, NULL, NULL, &w, &h);

	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	SDL_RenderCopy(rend, message, NULL, &dst);

	// Always free memory! //
	SDL_FreeSurface(temp);

	// Close the font. //
	TTF_CloseFont(font);

	return true;
}

bool Simplefuncs::drawText(Uint16* text, char* fontfile, int size, int x, int y, int fR, int fG, int fB)
{
	// Open our font and set its size to the given parameter //
	TTF_Font* font = nullptr;
	font = TTF_OpenFont(fontfile, size);
	if (font == nullptr){
		throw std::runtime_error(TTF_GetError());
		return false;
	}

	SDL_Color textColor = { fR, fG, fB };   // text color 
	int w, h;
	SDL_Surface *temp;
	temp = TTF_RenderUNICODE_Blended(font, text, textColor);
	SDL_Texture* message = SDL_CreateTextureFromSurface(rend, temp);
	SDL_QueryTexture(message, NULL, NULL, &w, &h);

	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	SDL_RenderCopy(rend, message, NULL, &dst);

	// Always free memory! //
	SDL_FreeSurface(temp);

	// Close the font. //
	TTF_CloseFont(font);

	return true;
}