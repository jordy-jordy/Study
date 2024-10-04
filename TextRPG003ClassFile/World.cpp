#include "World.h"
#include "FightZone.h"
#include "Town.h"
#include "Player.h"
#include <BaseSystem/EngineDebug.h>
#include <BaseSystem/EngineFile.h>
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
	UTown TownZone0;
	TownZone0.SetName("초보 마을");

	UTown TownZone1;
	TownZone1.SetName("중급 마을");

	UFightZone FightZone;
	FightZone.SetName("초보 사냥터");

	while (true)
	{
		int NowWhere = _Player.GetPlaceNum();

		switch (NowWhere)
		{
		case 0:
			TownZone0.InPlayer(_Player);
			break;
		case 1:
			TownZone1.InPlayer(_Player);
			break;
		case 3:
			FightZone.InPlayer(_Player);
			break;
		default:
			break;
		}
	}

}

void UWorld::InPlayer(class UPlayer& _Player)
{
	UEngineFile File;
	File.SetPath("SaveFile.Dat");

	if (false == File.IsExits())
	{
		File.FileOpen("wb");

		PlayerNameSelect(_Player);
		const char* Name = _Player.GetName();

		File.Write(Name, NAMELEN);
	}
	else
	{
		File.FileOpen("rb");

		char Arr[100] = {};
		File.Read(Arr, NAMELEN);
		_Player.SetName(Arr);
	}

	PlayerZonePlay(_Player);
}