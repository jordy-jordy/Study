#include "Block.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/ConsoleEngine.h>
#include <EngineCore/ConsoleWindow.h>
#include <conio.h>

#include "BlockCover.h"


void Block::BeginPlay()
{
	Super::BeginPlay();
	UBlockCover::Ptr;

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, '@');
}

void Block::SetStackBlock()
{

	FIntPoint BlockPos = GetActorLocation();
	FIntPoint WindowSize = ConsoleEngine::GetEngine().GetWindow()->GetScreenSize();
	FIntPoint DownPos = BlockPos + FIntPoint::DOWN;

	UBlockCover* Window = UBlockCover::Ptr;
	Renderer* Renderer = Window->GetImageRenderer();

	if (BlockPos.Y == WindowSize.Y - 1 || BlockPos.Y + 1 == '@')
	{
		Renderer->RenderImage.SetPixel({ BlockPos.X, BlockPos.Y }, '@');
		SetActorLocation({ 0, 0 });
	}
}

//bool Block::CheckStack()
//{
//	FIntPoint BlockPos = GetActorLocation();
//
//	if (BlockPos.Y + 1 == '@')
//	{
//		return true;
//	}
//	return;
//}

void Block::MoveBlock()
{

	int Value = _kbhit();
	if (Value != 0)
	{
		int Select = _getch();

		switch (Select)
		{
		case 'A':
		case 'a':
			AddActorLocation(FIntPoint::LEFT);
			break;
		case 'D':
		case 'd':
			AddActorLocation(FIntPoint::RIGHT);
			break;
		case 'W':
		case 'w':
			AddActorLocation(FIntPoint::UP);
			break;
		case 'S':
		case 's':
			AddActorLocation(FIntPoint::DOWN);
			SetStackBlock();
			break;
		default:
			break;
		}

	}

}




void Block::Tick()
{
	Super::Tick();
	
	MoveBlock();


}


