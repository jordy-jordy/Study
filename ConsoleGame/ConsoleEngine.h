#pragma once
#include "ConsoleWindow.h"
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "ActorVector.h"

class ConsoleEngine
{
public:
	static void Start();

	static FIntPoint GetWindowSize()
	{
		return WindowSize;
	}

	static UConsoleWindow& GetWindow()
	{
		return Window;
	}

	static ConsoleEngine& GetEngine()
	{
		return *MainEngine;
	}

	template<typename ActorType>
	ActorType* SpawnActor()
	{
		ActorType* NewActor = new ActorType();
		AllActorVector.push_back(NewActor);
		NewActor->BeginPlay();
		return NewActor;
	}







private:
	ConsoleEngine();

	static FIntPoint WindowSize;
	static UConsoleWindow Window;

	static ConsoleEngine* MainEngine;

	ActorVector AllActorVector;

	void BeginPlay();
	void Tick();
	void Render();
};

