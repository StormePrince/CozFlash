#pragma once
#include "Card.h"

Card::Card(int Id, int Type, wstring Front, wstring Back, wstring Tip, wstring Info, wstring Options[])
{
	cardId = Id;
	type = Type;
	front = Front;
	back = Back;
	tip = Tip;
	info = Info;
	for (int c = 0; c < 4;c++)
		{
		options[c] = Options[c];
		}
}

wstring Card::getBack()
{
	return back;
}

wstring Card::getFront()
{
	return front;
}

wstring Card::getInfo()
{
	return info;
}

wstring Card::getoptions(int option)
{
	return options[option];
}

wstring Card::getTip()
{
	return tip;
}

bool Card::checkAnswer(wstring answer)
{
	if (back == answer)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Card::checkAnswer(int answer)
{
	if (back == options[answer])
	{
		return true;
	}
	else
	{
		return false;
	}
}


