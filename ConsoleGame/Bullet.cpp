#include "Bullet.h"
#include "Renderer.h"


void Bullet::BeginPlay()
{
	Super::BeginPlay();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, 'I');
}

void Bullet::Tick()
{
	Super::Tick();
	AddActorLocation(FIntPoint::UP);
}
