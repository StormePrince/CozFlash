#pragma once
#include "box.h"
#include "sprite.h"
class Button
{
public:
	Button();
	Button(int w,int h,Sprite back,string text);
	~Button();
	void changeBox(int w, int h);
	Box collisionBox;
	int width;
	int height;
	Sprite background;
	const char* buttonText;
};

