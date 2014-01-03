#pragma once
#include "Sprite.h"

Sprite::Sprite(SDL_Renderer* render, int h, int w, int l)
{
	height = h;
	width = w;
	tool = Simplefuncs(render);
	frame = 0;
	length = l;
	framerow = 0;
	framecol = 0;
	posx = 0;
	posy = 0;
}


Sprite::~Sprite()
{
}


bool Sprite::Load(char* File)
{
	
	image = tool.Load(File);
	if (image = NULL)
	{
		return false;
	}
	return true;
}


void Sprite::setposx(int x)
{
	posx = x;
}

void Sprite::setposy(int y)
{
	posy = y;
}

void Sprite::Draw() {

	framerow = frame / length;
	framecol = frame % length;
	tool.Draw(image,framerow*width,framecol*height,posx,posy,width,height,width,height);
}

void Sprite::Draw(int w, int h) {

	framerow = frame / length;
	framecol = frame % length;
	tool.Draw(image, framerow*width, framecol*height, posx, posy, width, height, w, h);
}

int Sprite::getframe()
{
	return frame;
}

void Sprite::nextFrame()
{
	frame++;
}