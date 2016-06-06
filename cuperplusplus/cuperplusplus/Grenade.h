#pragma once
#include "Room.h"
#include <map>
#include <algorithm>
class Grenade
{
public:
	Grenade();
	~Grenade();
	int minSpanningTree(std::map<Room*, Room*>);
private:
	std::vector<std::pair<Room*, Room*>> sortByRoomWeigths(std::map<Room*, Room*>);
};

