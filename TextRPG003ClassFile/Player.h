#pragma once
#include "FightUnit.h"

class Item;

class UPlayer : public UFightUnit
{
public:
	UPlayer();
	void Equip(class Item* Weapon);
	void SetPlaceNum(int _PlayerPlace)
	{
		PlaceNum = _PlayerPlace;
	}
	int GetPlaceNum()
	{
		return PlaceNum;
	}

protected:

private:
	class Item* Weapon = nullptr;
	int PlaceNum = 0;

};

