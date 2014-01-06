#pragma once
#include "Card.h"

Card::Card(int Id, int Type, int nop, wstring Front, wstring Back, wstring Tip, wstring Info, wstring Options[])
{
	cardId = Id;
	type = Type;
	front = Front;
	back = Back;
	tip = Tip;
	info = Info;
	numberOfOptions = nop;
	for (int c = 0; c < numberOfOptions;c++)
		{
		Options[c] = Options[c];
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

void Card::setFront(wstring change){ front = change; }

void Card::setBack(wstring change){ back = change; }

void Card::setTip(wstring change){ tip = change; }

void Card::setInfo(wstring change) { info = change; }

void Card::setOptions(wstring change[])
{
	for (int c = 0; c < numberOfOptions; c++)
	{
		options[c] = change[c];
	}
}

void Card::setId(int change){ cardId = change; }

void Card::setType(int change){ type = change; }

void Card::setNumberOfOptions(int change){ numberOfOptions = change; }




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


