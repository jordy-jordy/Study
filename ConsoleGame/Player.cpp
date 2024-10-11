#include "Player.h"
#include <conio.h>
#include "Enums.h"
#include "GlobalValue.h"
#include "ConsoleEngine.h"
#include "ConsoleImage.h"

void Player::BeginPlay()
{
	PlayerImage.Create({ 1, 1 }, 'O');
}

void Player::Tick(ConsoleImage* _BackBuffer)
{
	ConsoleEngine::GetWindow();
	ConsoleEngine::GetWindowSize();

	GlobalValue::WindowPtr;
	GlobalValue::WindowSize;


	int Value = _kbhit();
	Enums::GAMEDIR Dir = Enums::GAMEDIR::NONE;
	if (Value != 0)
	{
		int Select = _getch();

		switch (Select)
		{
		case 'A':
		case 'a':
			Dir = Enums::GAMEDIR::LEFT;
			break;
		case 'D':
		case 'd':
			Dir = Enums::GAMEDIR::RIGHT;
			break;
		case 'W':
		case 'w':
			Dir = Enums::GAMEDIR::UP;
			break;
		case 'S':
		case 's':
			Dir = Enums::GAMEDIR::DOWN;
			break;
		default:
			break;
		}

	}

	int WindowX = _BackBuffer->GetImageSizeX();
	int WindowY = _BackBuffer->GetImageSizeY();
	int& PlayerX = Pos.X;
	int& PlayerY = Pos.Y;

	switch (Dir)
	{
	case Enums::GAMEDIR::LEFT:
		if (PlayerX - 1 < 0)
		{
			PlayerX = 0;
		}
		else 
		{
			Pos += FIntPoint::LEFT;
		}
		break;
	case Enums::GAMEDIR::RIGHT:
		if (PlayerX + 1 == WindowX)
		{
			PlayerX = WindowX - 1;
		}
		else
		{
			Pos += FIntPoint::RIGHT;
		}
		break;
	case Enums::GAMEDIR::UP:
		if (PlayerY - 1 < 0)
		{
			PlayerY = 0;
		}
		else
		{
			Pos += FIntPoint::UP;
		}
		break;
	case Enums::GAMEDIR::DOWN:
		if (PlayerY + 1 == WindowY)
		{
			PlayerY = WindowY - 1;
		}
		else
		{
			Pos += FIntPoint::DOWN;
		}
		break;
	default:
		break;
	}


}

void Player::Render(ConsoleImage* _BackBuffer)
{
	_BackBuffer->Copy(Pos, PlayerImage);
}

void Player::SetActorLocation(FIntPoint _Pos)
{
	Pos = _Pos;
}

void Player::PlayerBuffer()
{
	int PlayerSizeX = ConsoleImage * _X);
}
