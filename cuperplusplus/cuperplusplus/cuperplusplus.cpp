// cuperplusplus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <windows.h>
#include "Game.h"


int _tmain(int argc, _TCHAR* argv[])
{
	MoveWindow(GetConsoleWindow(), 0, 0, 660, 660, TRUE);
	Game* currentGame = new Game();
	_CrtDumpMemoryLeaks();
	return 0;
}

