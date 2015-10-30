#pragma once
#include "Utils.h"
#include "Map.h"
#include "Player.h"
#include "list"
#include "ActionFactory.h"
#include "Action.h"

class Game
{
public:
	Game();
	~Game();
private:
	bool playing();
	void startGame();
	Map* map;
	Player* player;
	std::list<Action *> actions;
};

