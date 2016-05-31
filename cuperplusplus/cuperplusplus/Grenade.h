#pragma once
#include "Room.h"
#include <map>
class Grenade
{
public:
	Grenade();
	~Grenade();
	int minSpanningTree(std::map<Room*, Room*>, Room*);
};

