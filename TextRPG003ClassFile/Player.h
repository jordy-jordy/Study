#pragma once
#include "FightUnit.h"

class Item;

class UPlayer : public UFightUnit
{
public:
	UPlayer();

	void StatusRender() override;
	void Equip(class Item* Weapon);

	void SetCurZone(int _Index)
	{
		CurZoneIndex = _Index;
	}

	int GetCurZone()
	{
		return CurZoneIndex;
	}

protected:

private:
	class Item* Weapon = nullptr;
	int CurZoneIndex = 0;
	int EquipAtt = 0;
};

