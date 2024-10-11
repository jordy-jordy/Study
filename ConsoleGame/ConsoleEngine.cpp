#include "ConsoleEngine.h"
#include <Windows.h>
#include "GlobalValue.h"

FIntPoint ConsoleEngine::WindowSize;
UConsoleWindow ConsoleEngine::Window;

ConsoleEngine::ConsoleEngine()
{

}

void ConsoleEngine::Start()
{
	ConsoleEngine Engine;

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

	NewPlayer.BeginPlay();
}

void ConsoleEngine::Tick()
{
	ConsoleImage* BackBufferPtr = Window.GetBackBufferPtr();
	NewPlayer.Tick(BackBufferPtr);
}

void ConsoleEngine::Render()
{
	Window.Clear();

	ConsoleImage* BackBufferPtr = Window.GetBackBufferPtr();
	NewPlayer.Render(BackBufferPtr);

	Window.ScreenRender();
}