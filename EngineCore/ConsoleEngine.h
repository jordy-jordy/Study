#pragma once
#include <vector>

class ConsoleEngine
{
public:
	static void Start(class UserInit* _Init);


	static ConsoleEngine& GetEngine()
	{
		return *MainEngine;
	}

	class UConsoleWindow* GetWindow()
	{
		return Window;
	}

	template<typename ActorType>
	ActorType* SpawnActor()
	{
		ActorType* NewActor = new ActorType();
		AllActorVector.push_back(NewActor);
		NewActor->BeginPlay();
		return NewActor;
	}

	static void ApplicationEnd()
	{
		MainEngine->EngineActive = false;
	}

private:
	ConsoleEngine();

	static ConsoleEngine* MainEngine;

	class UConsoleWindow* Window;
	bool EngineActive = true;

	std::vector<class AActor*> AllActorVector;

	void BeginPlay(); 	void Tick(); 	void Render();
	void End();
};

class UserInit
{
public:
	virtual void UserBeginPlay(ConsoleEngine* _MainEngine) = 0;
};

