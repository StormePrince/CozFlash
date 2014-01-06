#pragma once
#include "base.h"



class Card
{
public:
	Card();
	~Card();
	Card(int Id, int Type, int numberofoptions, wstring Front, wstring Back, wstring Tip, wstring Info, wstring options[]);
	bool checkAnswer(wstring answer);
	bool checkAnswer(int answer);
	int getType();
	int getId();
	wstring getFront();
	wstring getBack();
	wstring getTip();
	wstring getInfo();
	wstring getoptions(int option);
	void setFront(wstring change);
	void setBack(wstring change);
	void setTip(wstring change);
	void setInfo(wstring change);
	void setOptions(wstring changes[]);
	void setNumberOfOptions(int change);
	void setId(int change);
	void setType(int change);
private:
	wstring front;
	wstring back;
	wstring tip;
	wstring info;
	wstring options[4];
	int numberOfOptions;
	int cardId;
	int type;

};



