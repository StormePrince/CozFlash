#pragma once
#include "Simplefuncs.h"
#include "base.h"
class Sprite
{
public:
	Sprite();
	~Sprite();
	Sprite(Simplefuncs* tool, int h, int w, int col,int row);
	Sprite(Simplefuncs* tool, int h, int w, int col, int row, int x, int y);
	bool load(char* File);
	bool load(SDL_Texture* texture);
	bool loadSurface(char* File);
	bool loadSurface(SDL_Surface* surface);
	void nextFrame();
	void test();
	void setFrame(int f);
	void setPosx(int x);
	void setPosy(int y);
	void addX(int x);
	void addY(int y);
	void subX(int x);
	void subY(int y);
	int getFrame();
	Simplefuncs* getPen();
	int getPosx();
	int getPosy();
	int getRow();
	int getCol();
	void showCenter();
	void showCenter(int w, int h);
	void showFrameCenter(int singleframe, int w, int h);
	void showFrameCenter(int singleframe);
	void animateCenter(int start, int finish);
	void animateCenter(int start, int finish, int w, int h);
	void show();
	void show(int w, int h);
	void showFrame(int singleframe, int w, int h);
	void showFrame(int singleframe);
	void animate(int start, int finish);
	void animate(int start, int finish, int w, int h);
private:
	Simplefuncs* pen = NULL;
	SDL_Texture* image = NULL;
	int columns;
	int rows;
	int height;
	int width;
	int frame;
	int centerPosx;
	int centerPosy;
	int posx;
	int posy;
	bool animating;
	int temp;
};


