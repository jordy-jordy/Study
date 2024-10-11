#pragma once
#include "ConsoleImage.h"


class Player
{
public:
	void BeginPlay();
	void Tick(ConsoleImage* _BackBuffer);
	void Render(ConsoleImage* _BackBuffer);

	void SetActorLocation(FIntPoint _Pos);

private:
	FIntPoint Pos;
	ConsoleImage PlayerImage;
};

