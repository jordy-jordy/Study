#include "Orc.h"
#include <iostream>

void AOrc::BeginPlay()
{
	AMonster::BeginPlay();
	SetName("Orc");

	SetMinAtt(5);
	SetMaxAtt(10);
	SetHp(100);
	SetRandomGold(50, 100);


}
