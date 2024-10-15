#pragma once
#include "ConsoleImage.h"
#include "Actor.h"
#include "ActorVector.h"


class Player : public AActor
{
public:
	void BeginPlay() override;
	void Tick() override;

	static Player* GetMainPlayer()
	{
		return MainPlayer;
	}

	const ActorVector& GetBulletVector()
	{
		return BulletVector;
	}


private:
	static Player* MainPlayer;
	ActorVector BulletVector;
};

