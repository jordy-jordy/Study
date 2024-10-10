#pragma once
#include "Zone.h"
#include "Enums.h"


class UFightZone : public UZone
{
public:
	void SetMonsterType(Enums::MONSTERTYPE _MonsterType)
	{
		MonsterType = _MonsterType;
	}

	UZone* InPlayer() override;

private:


	int MinMonsterCount = 1;
	int MaxMonsterCount = 1;



	class AMonster* CurMonster;
	Enums::MONSTERTYPE MonsterType = Enums::MONSTERTYPE::NONE;

	void CreateMonster();
};


