#include "Town.h"
#include <conio.h>
#include "Player.h"
#include "FightZone.h"

void UTown::InPlayer(class UPlayer& _Player)
{
	InMsgPrint();

	while (true)
	{
		_Player.StatusRender();

		std::cout << "0. 체력회복\n";
		std::cout << "1. 강화\n";
		std::cout << "2. 사냥터이동\n";
		std::cout << "3. 중급 마을로 이동\n";
		int Select = _getch();


		_Player.SetPlaceNum(0);

		switch (Select)
		{
		case '0':
			printf_s("아직 체력회복을 지원하지 않습니다.");
			_getch();
			break;
		case '1':
			printf_s("아직 강화를 지원하지 않습니다.");
			_getch();
			break;
		case '2':
		{
			printf_s("사냥터로 이동합니다.");
			_getch();
			return _Player.SetPlaceNum(3);
			break;
		}
		case '3':
			printf_s("중급 마을로 이동합니다.");
			_getch();
			return _Player.SetPlaceNum(2);
		default:
			break;
		}

	}
}
