#include "World.h"
#include "FightZone.h"
#include "Town.h"
#include "Player.h"
#include <conio.h>


void UWorld::PlayerNameSelect(class UPlayer& _Player)
{
	char InputName[100] = { 0, };

	bool IsNameInput = true;

	while (true)
	{
		if (true == IsNameInput)
		{
			system("cls");
			std::cout << "이름을 적어주세요" << std::endl;
			std::cin >> InputName;
		}

		system("cls");
		printf_s("당신의 이름은 %s입니다. 결정하시겠습니까?\n", InputName);
		printf_s("a. 결정\n");
		printf_s("b. 재입력\n");
		int Select = _getch();

		bool IsEnd = true;
		switch (Select)
		{
		case 'a':
		case 'A':
			IsEnd = true;
			break;
		case 'b':
		case 'B':
			IsEnd = false;
			IsNameInput = true;
			break;
		default:
			IsEnd = false;
			IsNameInput = false;
			printf_s("잘못된 선택입니다. 다시 선택해주세요\n", InputName);
			_getch();
			break;
		}

		if (true == IsEnd)
		{
			break;
		}
	}

	_Player.SetName(InputName);
}

void UWorld::PlayerZonePlay(class UPlayer& _Player)
{
	UTown TownZone;
	TownZone.SetName("초보마을");

	UFightZone FightZone;
	FightZone.SetName("초보사냥터");

	while (true)
	{
		TownZone.InPlayer(_Player);
	}

}

void UWorld::InPlayer(class UPlayer& _Player)
{
	// PlayerNameSelect(_Player);

	_Player.SetName("TestPlayer");

	PlayerZonePlay(_Player);
}