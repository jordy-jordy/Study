#pragma once
#include "ConsoleWindow.h"
#include "Player.h"

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

private:
	ConsoleEngine();

	static FIntPoint WindowSize;
	static UConsoleWindow Window;

	Player NewPlayer;

	void BeginPlay(); 

	void Tick(); 
	void Render(); 
};

