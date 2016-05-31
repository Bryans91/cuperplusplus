#pragma once
#include "Room.h"
#include <vector>
class Grenade
{
public:
	Grenade();
	~Grenade();
	int minSpanningTree(std::vector<Room*>, Room*);
};

