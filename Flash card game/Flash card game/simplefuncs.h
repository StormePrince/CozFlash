#pragma once
#include "base.h"
class Simplefuncs
{
public:
	Simplefuncs();
	void test();
	Simplefuncs(SDL_Renderer* render);
	~Simplefuncs();

	SDL_Texture* Load(char* File);
	bool Draw(SDL_Texture* src, int x, int y, int xd, int yd, int width, int height, int widthd, int heightd);
	bool Drawtext(string text, int x, int y, int size, int fR, int fG, int fB, int bR, int bG, int bB);
private:
	SDL_Renderer* rend;

	
	
};

