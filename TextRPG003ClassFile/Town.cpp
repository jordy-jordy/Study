#include "Town.h"
#include <conio.h>
#include "Player.h"
#include "BlackSmith.h"

UTown::UTown()
{
	BS.SetParent(this);
}

UZone* UTown::InPlayer(class UPlayer& _Player)
{
	InMsgPrint();

	while (true)
	{
		system("cls");
		ZonePrint();
		_Player.StatusRender();

		std::cout << "0. 체력회복\n";
		std::cout << "1. 강화\n";
		std::cout << "2. 다른 지역으로 이동\n";

		int Select = _getch();

		switch (Select)
		{
		case '1':
		{
			BS.InPlayer(_Player);
			break;
		}
		case '2':
		{
			UZone* NextZone = ConnectingProgress();
			return NextZone;
			break;
		}
		case '0':
		case '3':
			printf_s("아직 완성되지 않은 기능입니다.");
			_getch();
			return nullptr;
		default:
			break;
		}

	}
}
