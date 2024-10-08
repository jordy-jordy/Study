
// 오브젝트들이 활동하는 공간을 Stage로 분류

#pragma once
#include "SafeZone.h"
#include "BattleZone.h"


class UStage
{
public:
	void Ustage();
	void ZoneInit();

protected:

private:
	USafeZone Town_Level0;
	USafeZone Town_Level10;
	UBattleZone Field_Level0;
};

