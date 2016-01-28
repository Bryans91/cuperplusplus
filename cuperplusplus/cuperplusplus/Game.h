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
	bool cheat = false;
	bool fighting = false;
	bool showStats = false;
	bool showInventory = false;
	std::string actions;
	void startGame();
	void handleInput(std::string);
	void generateDungeon(std::string, std::string);

};

