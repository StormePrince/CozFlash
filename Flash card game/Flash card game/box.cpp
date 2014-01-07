#include "box.h"


Box::Box(int l, int r,int t,int b)
{
	xl = l;
	xr = r;
	yt = t;
	yb = b;
}

Box::Box()
{

}

Box::~Box()
{
}

bool Box::compareBoxHor(Box b)
{
	return false;
}

bool Box::compareBoxVer(Box b)
{
	return true;
}

bool Box::holds(Box b)
{
	if (xl>b.xl && xr<b.xl && yt<b.yt && yb>b.yb )
	{
		return true;
	}
	return false;
}