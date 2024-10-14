#pragma once
#include "ConsoleImage.h"



class UConsoleWindow
{

public:
	UConsoleWindow();




	void BeginPlay();

	void ScreenRender();

	void SetScreenSize(FIntPoint _Value)
	{
		SetScreenSize(_Value.X, _Value.Y);
	}

	void SetScreenSize(int _X, int _Y);

	void WindowSetPixel(FIntPoint _Value, char _Text = '*')
	{
		WindowSetPixel(_Value.X, _Value.Y, _Text);
	}

	void WindowSetPixel(int _X, int _Y, char _Text = '*');

	void Clear();

	ConsoleImage* GetBackBufferPtr()
	{
		return &BackBuffer;
	}

	ConsoleImage& GetBackBufferRef()
	{
		return BackBuffer;
	}

private:
	int FrameDelay = 250;
	ConsoleImage BackBuffer;
};

