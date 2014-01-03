#pragma once
#include "Simplefuncs.h"
#include "base.h"
class Sprite
{
public:
	Sprite();
	~Sprite();
	Sprite(SDL_Renderer* render, int h, int w, int l);

	bool Load(char* File);

	void nextFrame();
	void test();

	void setframe(int f)
		{
		frame = f;
		}
	void setposx(int x);
	void setposy(int y);
	int getframe();
	void Draw();
	void Draw(int w,int h);
private:
	Simplefuncs tool;
	SDL_Texture* image = NULL;
	int height;
	int width;
	int framerow;
	int framecol;
	int frame;
	int length;
	int posx;
	int posy;
};


