#include "Player.h"
#include <iostream>



UPlayer::UPlayer()
{
}

void UPlayer::StatusTextPrint()
{
	printf_s("���ݷ� : %d ~ %d + %d\n", MinAtt, MaxAtt, EquipAtt);
	printf_s("ü�� : %d\n", Hp);
	printf_s("��� : %d\n", Gold);
}

void UPlayer::Equip(class Item* Weapon)
{

}
