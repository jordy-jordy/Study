#include "TetrisInit.h"
#include <EngineCore/ConsoleEngine.h>
#include <EngineCore/ConsoleWindow.h>

#include "Block.h"
#include "BlockCover.h"


void TetrisInit::UserBeginPlay(ConsoleEngine* _MainEngine)
{
	// 시작을 합니다.
	_MainEngine->GetWindow()->SetScreenSize({3, 5});
	_MainEngine->SpawnActor<UBlockCover>();
	_MainEngine->SpawnActor<Block>();
}