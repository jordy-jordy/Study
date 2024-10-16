
#include <iostream>
#include <EngineCore/ConsoleEngine.h>
#include <TetrisContents/TetrisInit.h>

int main()
{
    TetrisInit Init;
    ConsoleEngine::Start(&Init);
}

