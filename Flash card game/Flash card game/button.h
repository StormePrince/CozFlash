#pragma once
#include "box.h"
#include "sprite.h"
class Button
{
public:
	Button();
	Button(int w, int h, Sprite back, char* text);
	Button(int w,int h,Sprite back,char* text,int i);
	~Button();
	void changeBox(int x,int y,int w, int h);
	bool load(char* fontFile, char* back, int size, int r, int g, int b);
	Box collisionBox;
	int width;
	int height;
	Sprite image;
	char* buttonText;
};

