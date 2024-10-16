#include "ConsoleWindow.h"
#include <iostream>

UConsoleWindow::UConsoleWindow()
{

}

void UConsoleWindow::SetScreenSize(int _X, int _Y)
{
	BackBuffer.Create(_X, _Y, '*');
}

void UConsoleWindow::BeginPlay()
{
	Clear();
}

void UConsoleWindow::Clear()
{
	system("cls");
	BackBuffer.Clear('*');
}

void UConsoleWindow::WindowSetPixel(int _X, int _Y, char _Text /*= '*'*/)
{
}

void UConsoleWindow::ScreenRender()
{
	FIntPoint Point = BackBuffer.GetImageSize();

	for (size_t y = 0; y < Point.Y; y++)
	{
		std::vector<char>& Line = BackBuffer.GetLineRef(y);
		char* Ptr = &Line[0];
		printf_s(Ptr);
		printf_s("\n");
	}
}