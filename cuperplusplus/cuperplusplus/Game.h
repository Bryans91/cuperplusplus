#pragma once
#include "Utils.h"
#include "Map.h"
#include "Player.h"
#include "string"

class Game
{
public:
	Game();
	~Game();
	void endGame();
private:
	bool playing;
	Map* map;
	Player* player;
	std::string actions;
	void startGame();
};

