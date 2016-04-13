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
	std::string name;
	Player* player;
	bool cheat = false;
	bool fighting = false;
	bool showStats = false;
	bool showInventory = false;
	bool affected = false;
	bool compass = false;
	bool talisman = false;
	std::string actions, size, difficulty, effect = "";
	void startGame();
	void checkHP();
	void handleInput(std::string);
	int handleItemInput(std::string);
	void generateDungeon(std::string, std::string);
	void affect();

};

