#include "World.h"
#include "FightZone.h"
#include "Town.h"
#include <conio.h>


void UWorld::InPlayer(class UPlayer& _Player)
{
	char InputName[100] = { 0, };

	system("cls");

	std::cout << "�̸��� �����ּ���" << std::endl;
	std::cin >> InputName;

	while (true)
	{


		system("cls");
		printf_s("����� �̸��� %s�Դϴ�. �����Ͻðڽ��ϱ�?\n", InputName);
		printf_s("a. ����\n");
		printf_s("b. ���Է�\n");
		int Select = _getch();
		int IsEnd = 0;
		switch (Select)
		{
		case 'a':
		case 'A':
			IsEnd = 0;
			break;
		case 'b':
		case 'B':
			IsEnd = 1;
			system("cls");

			std::cout << "�̸��� �����ּ���" << std::endl;
			std::cin >> InputName;
			break;
		default:
			printf_s("�߸��� �����Դϴ�. �ٽ� �������ּ���\n", InputName);
			_getch();
			IsEnd = 2;
			break;
		}

		if (0 == IsEnd)
		{
			break;
		}

	}

	// �������ʱ��� ���⼭ �� ������� ����
	// ������ ������ FightZone�� ��� �ȴ�.
	// ���� ��� �������� 

	// new�� �� ����� �ϴ°ų�?
	// 8�Ⱑ
	UTown TownZone;
	TownZone.SetName("�ʺ�����");

	// 10�Ⱑ
	UFightZone FightZone;
	FightZone.SetName("�ʺ������");

	while (true)
	{
		TownZone.InPlayer(_Player);
	}



}