#pragma once
#include "base.h"
class Simplefuncs
{
public:
	Simplefuncs();
	void test();
	Simplefuncs(SDL_Renderer* render);
	~Simplefuncs();


	bool draw(SDL_Texture* src, int x, int y, int xd, int yd, int width, int height, int widthd, int heightd);
	bool draw(SDL_Texture* src, int x, int y, int xd, int yd, int width, int height);
	bool drawText(char* string, char* fontfile,int size, int x, int y, int fR, int fG, int fB);
	bool drawTextSolid(char* string, char* fontfile, int size, int x, int y, int fR, int fG, int fB);
	SDL_Surface* saveText(char* string, char* fontfile, int size,  int fR, int fG, int fB);
	SDL_Surface* saveTextSolid(char* string, char* fontfile, int size, int fR, int fG, int fB);
	bool drawText(Uint16* string, char* fontfile,int size, int x, int y, int fR, int fG, int fB);
	SDL_Renderer* getRend();
private:
	SDL_Renderer* rend;

	
	
};

