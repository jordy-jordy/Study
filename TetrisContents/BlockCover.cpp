#include "BlockCover.h"
#include <EngineCore/Renderer.h>
#include <conio.h>

UBlockCover* UBlockCover::Ptr = nullptr;

void UBlockCover::BeginPlay()
{
	Super::BeginPlay();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 3, 5 }, '-');



	UBlockCover::Ptr = this;
}

void UBlockCover::Tick()
{

}

