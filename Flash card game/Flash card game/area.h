#pragma once
#include "base.h"
#include "Card.h"

using namespace std;

class area
{
public:
	area(int id, wstring name, int* locks, int cardIds);
	int getAreaID();
	wstring getName();
	int getLocks;
	int getCardIds;
private:
	wstring areaName;
	int areaId;
	vector<int> areaLocks;
	vector<int> cards;

};


