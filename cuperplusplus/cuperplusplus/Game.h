#pragma once
#include "Utils.h"
#include "Dungeon.h"
#include "Player.h"
#include "string"


class Game
{
public:
	Game();
	~Game();
private:

	Dungeon* dungeon;
	bool playing;
	Player* player;
	std::string actions;
	void startGame();
	void generateDungeon();

};

