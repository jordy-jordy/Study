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

		std::cout << "0. ü��ȸ��\n";
		std::cout << "1. ��ȭ\n";
		std::cout << "2. ������̵�\n";
		std::cout << "3. �߱� ������ �̵�\n";
		int Select = _getch();


		_Player.SetPlaceNum(0);

		switch (Select)
		{
		case '0':
			printf_s("���� ü��ȸ���� �������� �ʽ��ϴ�.");
			_getch();
			break;
		case '1':
			printf_s("���� ��ȭ�� �������� �ʽ��ϴ�.");
			_getch();
			break;
		case '2':
		{
			printf_s("����ͷ� �̵��մϴ�.");
			_getch();
			return _Player.SetPlaceNum(3);
			break;
		}
		case '3':
			printf_s("�߱� ������ �̵��մϴ�.");
			_getch();
			return _Player.SetPlaceNum(2);
		default:
			break;
		}

	}
}
