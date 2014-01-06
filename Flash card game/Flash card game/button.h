#pragma once
#include "box.h"
#include "sprite.h"
class button
{
public:
	button();
	button(int w,int h,Sprite* background,string text);
	~button();
	Box collisionBox;
	int w;
	int h;
	Sprite background;
	string buttonText;
};

