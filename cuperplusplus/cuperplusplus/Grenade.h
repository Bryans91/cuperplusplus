#pragma once
#include "Room.h"
#include <map>
class Grenade
{
public:
	Grenade();
	~Grenade();
	int minSpanningTree(std::map<Room*, Room*>);
private:
	std::map<Room*, Room*> sortByRoomWeigths(std::map<Room*, Room*>);
};

