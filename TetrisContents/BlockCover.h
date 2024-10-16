#pragma once
#include <EngineCore/Actor.h>


class UBlockCover : public AActor
{
public:
	void BeginPlay() override;
	void Tick() override;

	static UBlockCover* Ptr;


};

