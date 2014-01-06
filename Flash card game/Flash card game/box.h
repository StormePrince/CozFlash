#pragma once
#include "base.h"
class Box
{
public:
	Box();
	Box(int a,int b, int c,int d);
	~Box();
	bool compareBoxVer(Box b);
	bool compareBoxHor(Box b);
	bool holds(Box b);
	int xl;
	int xr;
	int yt;
	int yb;

};

