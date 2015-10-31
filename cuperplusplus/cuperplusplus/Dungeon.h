#pragma once
#include <map>
#include "Room.h"
#include "DungeonLayer.h"
using std::map;


class Dungeon
{
public:
	Dungeon();
	~Dungeon();
	void setLevel(int level, DungeonLayer* layer);
	void loadLevel(int level);
	Room* getFirstRoom();
	Room* getLastRoom();

private:
	int level;
	map<int, DungeonLayer*> Levels;


};
