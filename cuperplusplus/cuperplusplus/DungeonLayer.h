#pragma once
#include <vector>
#include "Room.h"
class DungeonLayer
{
public:
	DungeonLayer();
	~DungeonLayer();
	void setEnd(Room* end);
	void setStart(Room* s);
	Room* getStart();
	Room* getEnd();


private:
	Room* start;
	Room* end;
	std::vector<Room*> roomList;
	std::vector<std::vector<Room*>> mapLayout;
};


