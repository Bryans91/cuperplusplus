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
	void setConnectedRooms(std::vector<std::pair<Room*, Room*>>);
	Room* getStart();
	Room* getEnd();
	std::vector<std::pair<Room*, Room*>> getConnectedRooms();
	void setMap(std::vector<std::vector<Room*>> map);
	void setRooms(std::vector<Room*> rooms);
	std::string getDungeonMap(bool, Room*);
	void removeRoomConnections();
	DungeonLayer* clone();


private:
	bool cloned = false;
	std::vector<Room*> cloneRooms();
	Room* start;
	Room* end;
	std::vector<std::pair<Room*, Room*>> connectedRooms;
	std::vector<Room*> roomList;
	std::vector<std::vector<Room*>> mapLayout;
};


