#include "Block.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/ConsoleEngine.h>
#include <EngineCore/ConsoleWindow.h>
#include <conio.h>

#include "BlockCover.h"


void Block::BeginPlay()
{
	Super::BeginPlay();


	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, '@');
}

void Block::Tick()
{
	Super::Tick();
	MoveBlock();
}

void Block::SetStackBlock()
{
	UBlockCover* Window = UBlockCover::Ptr;
	Renderer* Renderer = Window->GetImageRenderer();

	FIntPoint CurPos = GetActorLocation();
	FIntPoint WindowSize = ConsoleEngine::GetEngine().GetWindow()->GetScreenSize();

	if (CurPos.Y == WindowSize.Y - 1 || IsBlockBelow())
	{
		Renderer->RenderImage.SetPixel({ CurPos.X, CurPos.Y }, '@');
		SetActorLocation({ 0, 0 });
	}
}

bool Block::IsBlockBelow()
{
	UBlockCover* Window = UBlockCover::Ptr;
	Renderer* Renderer = Window->GetImageRenderer();

	FIntPoint CurPos = GetActorLocation();
	FIntPoint BelowPos = CurPos + FIntPoint::DOWN; 

	if (Renderer->RenderImage.GetPixel(BelowPos.X,BelowPos.Y) == '@')
	{
		return true; 
	}

	return false; 
}

void Block::MoveBlock()
{
	FIntPoint CurPos = GetActorLocation();
	FIntPoint WindowSize = ConsoleEngine::GetEngine().GetWindow()->GetScreenSize();

	int Value = _kbhit();
	if (Value != 0)
	{
		int Select = _getch();

		switch (Select)
		{
		case 'A':
		case 'a':
			if (CurPos.X > 0)
			{
				AddActorLocation(FIntPoint::LEFT);
			}
			break;
		case 'D':
		case 'd':
			if (CurPos.X < WindowSize.X - 1)
			{
				AddActorLocation(FIntPoint::RIGHT);
			}
			break;
		case 'W':
		case 'w':
			if (CurPos.Y > 0)
			{
				AddActorLocation(FIntPoint::UP);
			}
			break;
		case 'S':
		case 's':
			if (IsBlockBelow())
			{
				SetStackBlock(); 
			}
			else
			{
				AddActorLocation(FIntPoint::DOWN); 
				SetStackBlock();
			}
			break;
		default:
			break;
		}
	}
}

