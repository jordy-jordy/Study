#include "UnvisibleWindow.h"


void UnvisibleWindow::BeginPlay()
{
	Super::BeginPlay();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 3, 5 }, '-');

	// Render->RenderImage.SetPixel({0,4}, '@');
}

