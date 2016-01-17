#pragma once
#include "Dungeon.h"
#include "DungeonLayer.h"

class DungeonGenerator
{
public:
	DungeonGenerator();
	~DungeonGenerator();
	Dungeon* GenerateDungeon(std::string);
	static int RandomNumberGenerator(int lowest, int highest);
	

private:
	int dungeonWidth, dungeonHeight;
	DungeonLayer* GenerateLayer(int layer);

};
