#include "Player.h"
#include <iostream>

UPlayer::UPlayer()
{
}


void UPlayer::StatusRender()
{
    UStatusUnit::TopLine();
    UStatusUnit::MidLine();
    UStatusUnit::BotLine();
}

void UPlayer::Equip(class Item* Weapon)
{

}