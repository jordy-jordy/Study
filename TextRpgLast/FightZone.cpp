#include "FightZone.h"
#include "Monster.h"
#include "Player.h"
#include <conio.h>
#include "Orc.h"
#include "Goblin.h"
#include <BaseSystem/EngineDebug.h>
#include "TextRpgCore.h"
#include "Orc.h"
#include "Goblin.h"

void UFightZone::CreateMonster()
{

	switch (MonsterType)
	{
	case Enums::MONSTERTYPE::GOBLIN:
	{
		AGoblin* Ptr = new AGoblin();
		CurMonster = Ptr;
		break;
	}
	case Enums::MONSTERTYPE::ORC:
		CurMonster = new AOrc();
		break;
	default:
		break;
	}


	CurMonster->BeginPlay();
}


UZone* UFightZone::InPlayer()
{
	if (Enums::MONSTERTYPE::NONE == MonsterType)
	{
		MSGASSERT("몬스터 타입이 정해지지 않은 사냥터입니다.");
		return nullptr;
	}

	InMsgPrint();
	_getch();




	CreateMonster();
	APlayer& Player = TextRpgCore::GetPlayer();
	AMonster& Monster = *CurMonster;

	while (true)
	{
		Player.StatusRender();
		Monster.StatusRender();
		_getch();

		break;
	}

	if (nullptr != CurMonster)
	{
		delete CurMonster;
		CurMonster = nullptr;
	}


	return GetZone(0);
}