#pragma once
#include "Utils.h"
#include "Dungeon.h"
#include "Player.h"
#include "Room.h"
#include "map"
#include "string"
#include "DungeonGenerator.h"


class Game
{
public:
	Game();
	~Game();
	void endGame();
private:

	Dungeon* dungeon;
	bool playing;
	Player* player;
	std::string actions;
	void startGame();
	void handleInput(std::string);
	void generateDungeon();

};

