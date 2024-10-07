#include "BlackSmith.h"
#include "Player.h"
#include <BaseSystem/EngineDebug.h>
#include <conio.h>


//void BlackSmith::Upgrade()
//{
//	int UpgrageValue = rand() % 10;
//	int CountValue = 0;
//	if (5 >= UpgrageValue)
//	{
//		_Player.SetGold(_Player.GetGold() - 100);
//	}
//	else
//	{
//		_Player.SetGold(_Player.GetGold() - 100);
//		Count += 1;
//	}
//
//}



void BlackSmith::InPlayer(class UPlayer& _Player/*, int& Result*/)
{
	if (nullptr == ParentZone)
	{
		MSGASSERT("부모존이 세팅되지 않았습니다");
		return;
	}

	_Player.SetGold(1000000);
	srand(time(nullptr));

	while (true)
	{
		system("cls");
		_Player.StatusRender();
		std::cout << "1. 강화\n";
		std::cout << "2. 나간다\n";
		int Select = _getch();

		int Gold = _Player.GetGold();
		int Probability = rand() % 10;
		int UpgradeValue = _Player.GetEquipAtt();
		int MaxUpgrade = 16;

		switch (Select)
		{
		case '1':

			for (size_t i = 0; i < MaxUpgrade; i++)
			{
				if (i < 6)
				{
					_Player.SetGold(Gold - (UpgradeValue + 1) * 100);
					_Player.SetEquipAtt(UpgradeValue + 1);

				}
				else if (6 > Probability)
				{
					_Player.SetGold(Gold - (UpgradeValue + 1) * 100);
				}
				else
				{
					_Player.SetGold(Gold - (UpgradeValue+1) * 100);
					_Player.SetEquipAtt(UpgradeValue + 1);
				}
			}
			break;

		case '2':
			return;
		default:
			break;
		}
	}
}