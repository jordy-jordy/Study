#pragma once
#include <BaseSystem/EngineMath.h>
#include "ConsoleImage.h"


class AActor
{


public:
	virtual void BeginPlay();
	virtual void Tick();

	void Render(ConsoleImage* _BackBuffer);

	void SetActorLocation(FIntPoint _Pos);

	void AddActorLocation(FIntPoint _Pos);

	FIntPoint GetCurPos()
	{
		return Pos;
	}


protected:
	ConsoleImage RenderImage;

private:
	FIntPoint Pos;
};

typedef AActor Super;