#pragma once
#include "map"
#include "list"
#include "string"
#include "Map.h"
#include "Enemy.h"
#include "Room.h"
#include "Character.h"
#include <iostream>

class Player : public Character
{
private:
	Room *currentRoom;
	int experience;
	std::map < std::string, Room> inputMap;
public:
	Player(std::string aName);//, Map *map
	~Player();
	//void Move(Room *_room){ this->currentRoom = _room; _room->setVisited(); };
	Room *getCurrentRoom(){ return currentRoom; };
	enum Action
	{
		eflee = 1,
		efight = 2,
		esearch = 3,
		erest = 4,
		echeckMap = 5,
		estats = 6,
		esave = 7,
		eAdmin = 8
	};

	Action chooseAction();

	void fight();
	void flee();
	void search();
	void loot(std::list<Enemy *> enemies);
	void rest();
	void stats();
	void cheat(Map *map);


};

