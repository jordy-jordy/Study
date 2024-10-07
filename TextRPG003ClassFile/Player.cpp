#include "Player.h"
#include <iostream>



UPlayer::UPlayer()
{
}

void UPlayer::StatusTextPrint()
{
	printf_s("공격력 : %d ~ %d + %d\n", MinAtt, MaxAtt, EquipAtt);
	printf_s("체력 : %d\n", Hp);
	printf_s("골드 : %d\n", Gold);
}

void UPlayer::Equip(class Item* Weapon)
{

}
