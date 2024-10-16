#pragma once
#include <EngineBase/EngineMath.h>
#include <vector>




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

	inline std::vector<char> GetLine(size_t _Y)
	{
		return Pixels[_Y];
	}

	inline std::vector<char>& GetLineRef(size_t _Y)
	{
		return Pixels[_Y];
	}

	inline char GetPixel(int _X, int _Y)
	{
		return Pixels[_Y][_X];
	}

	inline FIntPoint GetImageSize() const
	{
		return ImageSize;
	}

	void Copy(FIntPoint _Offset, ConsoleImage& _Image);

	void SetPixel(FIntPoint _Pos, char _Char);

private:
	std::vector<std::vector<char>> Pixels;
	FIntPoint ImageSize;
};

