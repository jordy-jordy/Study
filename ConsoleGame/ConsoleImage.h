#pragma once
#include <BaseSystem/EngineMath.h>




class ConsoleImage
{

public:
	~ConsoleImage();

	void Release();


	void Clear(char _Clearchar);

	void Create(FIntPoint _Size, char _BaseChar)
	{
		Create(_Size.X, _Size.Y, _BaseChar);
	}

	void Create(int _X, int _Y, char _BaseChar);

	inline char* GetLine(int _Y)
	{
		return Arr[_Y];
	}

	inline char GetPixel(int _X, int _Y)
	{
		return Arr[_Y][_X];
	}

	inline int GetImageSizeX()
	{
		return X;
	}

	inline int GetImageSizeY()
	{
		return Y;
	}

	void Copy(FIntPoint _Offset, ConsoleImage& _Image);

	void SetPixel(FIntPoint _Pos, char _Char);

private:
	char** Arr = nullptr;
	int X = 0;
	int Y = 0;
};

