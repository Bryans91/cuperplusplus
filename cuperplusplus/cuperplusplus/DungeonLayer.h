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
	void setConnectedRooms(std::map<Room*, Room*>);
	Room* getStart();
	Room* getEnd();
	std::map<Room*, Room*> getConnectedRooms();
	void setMap(std::vector<std::vector<Room*>> map);
	void setRooms(std::vector<Room*> rooms);
	std::string getDungeonMap(bool, Room*);


private:
	Room* start;
	Room* end;
	std::map<Room*, Room*> connectedRooms;
	std::vector<Room*> roomList;
	std::vector<std::vector<Room*>> mapLayout;
};


