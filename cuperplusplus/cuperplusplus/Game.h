#pragma once
#include "Utils.h"
#include "Dungeon.h"
#include "Player.h"
#include <vector>
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
	Dungeon* dungeon;
	Player* player;
	std::vector<Action *> actions;

};

