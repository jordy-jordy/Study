#pragma once
#include <EngineBase/EngineMath.h>
#include "ConsoleImage.h"


class AActor
{


public:
	virtual void BeginPlay();
	virtual void Tick();

	void Render(ConsoleImage* _BackBuffer);

	void SetActorLocation(FIntPoint _Pos);

	void AddActorLocation(FIntPoint _Pos);

	FIntPoint GetActorLocation()
	{
		return Pos;
	}

	class Renderer* CreateDefaultSubObject();

	class Renderer* GetImageRenderer()
	{
		return ImageRenderer;
	}

protected:

private:
	class Renderer* ImageRenderer;
	FIntPoint Pos;
};

typedef AActor Super;