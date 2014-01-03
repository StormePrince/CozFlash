#pragma once
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


class Card
{
public:
	
	Card(int Id, int Type, wstring Front, wstring Back, wstring Tip, wstring Info, wstring Options[]);
	int getType();
	int getId();
	wstring getFront();
	wstring getBack();
	wstring getTip();
	wstring getInfo();
	wstring getoptions(int option);
	bool checkAnswer(wstring answer);
	bool checkAnswer(int answer);
private:
	wstring front;
	wstring back;
	wstring tip;
	wstring info;
	wstring options[4];
	int cardId;
	int type;

};



