// cuperplusplus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <crtdbg.h>
#include <windows.h>
#include "Game.cpp"
//#include <vld.h>
#define _CRTDBG_MAP_ALLOC



int _tmain(int argc, _TCHAR* argv[])
{
	MoveWindow(GetConsoleWindow(), 0, 0, 660, 660, TRUE);
	Game *currentGame = new Game();
	delete currentGame;
	return 0;
}

