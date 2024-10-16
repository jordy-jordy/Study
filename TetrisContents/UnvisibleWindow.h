#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Renderer.h>
#include <conio.h>


class UnvisibleWindow : public AActor
{
public:
	void BeginPlay() override;
	static UnvisibleWindow* Render()
	{
	}

};

