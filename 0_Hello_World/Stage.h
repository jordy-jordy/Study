
// ������Ʈ���� Ȱ���ϴ� ������ Stage�� �з�

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

