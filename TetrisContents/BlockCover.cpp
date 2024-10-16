#include "BlockCover.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/ConsoleEngine.h>
#include <EngineCore/ConsoleWindow.h>
#include <conio.h>

UBlockCover* UBlockCover::Ptr = nullptr;


void UBlockCover::BeginPlay()
{
	Super::BeginPlay();

	FIntPoint WindowSize = ConsoleEngine::GetEngine().GetWindow()->GetScreenSize();
	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({WindowSize}, '-');

	UBlockCover::Ptr = this;
}

void UBlockCover::Tick()
{

}

