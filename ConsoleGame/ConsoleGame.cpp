﻿
#include <iostream>

#include "ConsoleEngine.h"
#include <Windows.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	ConsoleEngine::Start();

}
