#pragma once
#include "Sprite.h"

Sprite::Sprite(Simplefuncs* tool, int h, int w, int col, int row)
{
	height = h;
	width = w;
	pen = tool;
	frame = 0;
	columns = col;
	rows = row;
	posx = 0;
	posy = 0;
	temp = 0;
	animating = false;
	image = NULL;
}


Sprite::~Sprite()
{
}

Sprite::Sprite()
{
}


bool Sprite::load(char* file)
{
	if (file == NULL) 
	{
		throw std::runtime_error(SDL_GetError());
		return false;
	}
	image = LOAD(pen->getRend(), file);
	return true;
}

bool Sprite::load(SDL_Texture* spritesheet)
{
	if (spritesheet == NULL) 
	{
		throw std::runtime_error(SDL_GetError());
		return false;
	}
	image = spritesheet;
	return true;
}


void Sprite::setPosx(int x)
{
	posx = x;
}

void Sprite::setPosy(int y)
{
	posy = y;
}

void Sprite::show() 
{
	int framerow = frame / columns;
	int framecol = frame % columns;
	pen->draw(image,framecol*width,framerow*height,posx,posy,width,height,width,height);
}

void Sprite::show(int w, int h)
{
	int framerow = frame / columns;
	int framecol = frame % columns;
	pen->draw(image, framecol*width, framerow*height, posx, posy, width, height, w, h);
}

void Sprite::showFrame(int singleframe)
{
	temp = frame;
	frame = singleframe;
	show();
	frame = temp;
}

void Sprite::showFrame(int singleframe, int w, int h)
{
	temp = frame;
	frame = singleframe;
	show(w,h);
	frame = temp;
}


void Sprite::animate(int start, int finish) 
{
	if (animating == false)
	{
		int temp = frame;
		animating = true;
		setFrame(start);
	}
		show();
		nextFrame();

	if (frame == finish)
	{
		frame = temp;
		animating = false;
	}
	
}

void Sprite::animate(int start, int finish, int w, int h) 
{
	if (animating == false)
	{
		int temp = frame;
		animating = true;
		frame = start;
	}

	show(w,h);
	frame++;

	if (frame == finish)
	{
		frame = temp;
		animating = false;
	}

}


void Sprite::setFrame(int f)
{
	frame = f;
}

void Sprite::addX(int x)
{
	posx += x;
}

void Sprite::addY(int y)
{
	posy += y;
}

void Sprite::subX(int x)
{
	posx -= x;
}

void Sprite::subY(int y)
{
	posy -= y;
}


int Sprite::getFrame()
{
	return frame;
}

int Sprite::getRow()
{
	int framerow = frame / columns;
	int framecol = frame % columns;
	return framerow;
}

int Sprite::getCol()
{
	int framerow = frame / columns;
	int framecol = frame % columns;
	return framecol;
}

int Sprite::getPosx()
{
	return posx;
}

int Sprite::getPosy()
{
	return posy;
}
void Sprite::nextFrame()
{
	frame++;
}