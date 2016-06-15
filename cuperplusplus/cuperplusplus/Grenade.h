#pragma once
#include "Room.h"
#include <map>
#include <algorithm>
#include "DungeonLayer.h"
class Grenade
{
public:
	Grenade();
	~Grenade();
	int minSpanningTree(DungeonLayer*);
private:
	std::vector<std::pair<Room*, Room*>> sortByRoomWeigths(std::vector<std::pair<Room*, Room*>>);
};

