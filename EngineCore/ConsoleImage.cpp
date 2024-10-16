#include "ConsoleImage.h"

ConsoleImage::~ConsoleImage()
{
	Release();
}

void ConsoleImage::Release()
{
	Pixels.clear();
}

void ConsoleImage::Create(int _X, int _Y, char _BaseChar)
{
	ImageSize = { _X, _Y };

	Pixels.resize(_Y);
	for (size_t y = 0; y < _Y; y++)
	{
		Pixels[y].resize(_X + 1);
	}

	Clear(_BaseChar);
}

void ConsoleImage::Clear(char _Clearchar)
{
	for (size_t y = 0; y < ImageSize.Y; y++)
	{
		for (size_t x = 0; x < ImageSize.X; x++)
		{
			Pixels[y][x] = _Clearchar;
		}
		Pixels[y][ImageSize.X] = 0;
	}
}

void ConsoleImage::SetPixel(FIntPoint _Pos, char _Char)
{
	if (0 > _Pos.X || ImageSize.X < _Pos.X)
	{
		return;
	}

	if (0 > _Pos.Y || ImageSize.Y < _Pos.Y)
	{
		return;
	}

	Pixels[_Pos.Y][_Pos.X] = _Char;
}

void ConsoleImage::Copy(FIntPoint _Offset, ConsoleImage& _Image)
{
	for (int y = 0; y < _Image.ImageSize.Y; y++)
	{
		for (int x = 0; x < _Image.ImageSize.X; x++)
		{
			FIntPoint SetPos = _Offset + FIntPoint{ x, y };

			char X = _Image.GetPixel(x, y);

			SetPixel(SetPos, X);
		}
	}
}