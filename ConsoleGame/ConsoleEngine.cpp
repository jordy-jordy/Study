#include "ConsoleEngine.h"
#include <Windows.h>
#include "GlobalValue.h"
#include "Actor.h"


ConsoleEngine* ConsoleEngine::MainEngine = nullptr;

FIntPoint ConsoleEngine::WindowSize;
UConsoleWindow ConsoleEngine::Window;

ConsoleEngine::ConsoleEngine()
{

}

void ConsoleEngine::Start()
{
	ConsoleEngine Engine;

	MainEngine = &Engine;

	Engine.BeginPlay();

	while (true)
	{
		Engine.Tick();
		Engine.Render();
		Sleep(250);
	}

}

void ConsoleEngine::BeginPlay()
{
	Window.BeginPlay();

	WindowSize.X = 20;
	WindowSize.Y = 10;

	GlobalValue::WindowPtr = &Window;

	Window.SetScreenSize(WindowSize);

	Player* NewPlayer = SpawnActor<Player>();
}

void ConsoleEngine::Tick()
{
	for (size_t i = 0; i < AllActorVector.size(); i++)
	{
		AllActorVector[i]->Tick();
	}
}

void ConsoleEngine::Render()
{
	Window.Clear();

	ConsoleImage* BackBufferPtr = Window.GetBackBufferPtr();
	for (size_t i = 0; i < AllActorVector.size(); i++)
	{
		AllActorVector[i]->Render(BackBufferPtr);
	}

	Window.ScreenRender();
}