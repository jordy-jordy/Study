#pragma once
#include "Zone.h"
#include "BlackSmith.h"

class UTown : public UZone
{
public:
	UTown();

	UZone* InPlayer(class UPlayer& _Player/*, int& Result*/);

	BlackSmith BS;
};

