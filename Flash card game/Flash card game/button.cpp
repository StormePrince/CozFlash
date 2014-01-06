#include "button.h"


Button::Button(int w, int h, Sprite back, string text)
{
	background = back;
	width = w;
	height = h;
	buttonText = text.c_str;
	collisionBox = Box(background.getPosx, background.getPosx+width, background.getPosy, background.getPosy+height);
}

Button::Button()
{
}


Button::~Button()
{
}

void Button::changeBox(int w,int h)
{
	collisionBox = Box(background.getPosx, background.getPosx + width, background.getPosy, background.getPosy + height);
}