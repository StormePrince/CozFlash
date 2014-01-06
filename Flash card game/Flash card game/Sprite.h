#pragma once
#include "Simplefuncs.h"
#include "base.h"
class Sprite
{
public:
	Sprite();
	~Sprite();
	Sprite(Simplefuncs* tool, int h, int w, int col,int row);

	bool load(char* File);
	bool load(SDL_Texture* texture);

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
	int getPosx();
	int getPosy();
	int getRow();
	int getCol();
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
	int posx;
	int posy;
	bool animating;
	int temp;
};


