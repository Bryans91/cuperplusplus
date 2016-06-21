#pragma once
#include <vector>
#include "Room.h"
class Compass
{
public:
	Compass();
	~Compass();
	void dijkstra(std::map<Room*, Room*> allConnectedRooms, Room* start, Room* stairs);
};
