#pragma once
#include "Utils.h"
#include "Map.h"
#include "Player.h"
#include "list"
#include "string"

class Game
{
public:
	Game();
	~Game();
private:
	bool playing;
	Map* map;
	Player* player;
	std::string actions;
	void startGame();
};

