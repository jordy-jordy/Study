#include "Monster.h"
#include "Renderer.h"
#include "Player.h"


void Monster::BeginPlay()
{
	Super::BeginPlay();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, 'M');
}

void Monster::Tick()
{



	Player* NewPlayer = Player::GetMainPlayer();

	const ActorVector& Bullets = NewPlayer->GetBulletVector();

	for (size_t i = 0; i < Bullets.size(); i++)
	{
		AActor* Bullet = Bullets[i];
		FIntPoint BlulletPos = Bullet->GetActorLocation();
		FIntPoint MonsterPos = this->GetActorLocation();

		if (MonsterPos == BlulletPos)
		{
			Bullet->GetImageRenderer()->Active = false;
			this->GetImageRenderer()->Active = false;
			return;
		}
	}


}


