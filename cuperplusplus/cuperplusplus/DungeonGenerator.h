#pragma once
#include "Dungeon.h"
#include "DungeonLayer.h"

class DungeonGenerator
{
public:
	DungeonGenerator();
	~DungeonGenerator();
	Dungeon* GenerateDungeon(int height, int width);
	static int RandomNumberGenerator(int lowest, int highest);
	

private:
	int dungeonWidth, dungeonHeight;
	Room GenerateRoom();
	Room* exitRoom;
	DungeonLayer* GenerateLayer(int layer);

};
