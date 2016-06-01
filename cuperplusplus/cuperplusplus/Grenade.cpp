#include "stdafx.h"
#include "Grenade.h"
#include "Room.h"
#include "Player.h"


Grenade::Grenade()
{
}


Grenade::~Grenade()
{
}

int Grenade::minSpanningTree(std::map<Room*, Room*> allConnectedRooms, Room* start) {
	int returnval = 0;
	// individual distances need to be set.
	std::vector<Room*> connected;
	std::map<Room*, Room*> tree;
	std::map<Room*, Room*>::iterator it = allConnectedRooms.begin();
	for (it = allConnectedRooms.begin(); it != allConnectedRooms.end(); ++it) {
		if (std::find(connected.begin(), connected.end(), it->first) != connected.end() && std::find(connected.begin(), connected.end(), it->second) != connected.end()) {
			//contains both rooms
			//collapsepath?
			break;
		}
		else if (std::find(connected.begin(), connected.end(), it->first) != connected.end()) {
			//contains first room
			connected.push_back(it->second);
			tree.insert(*it);
		}
		else if (std::find(connected.begin(), connected.end(), it->second) != connected.end()) {
			//contains second room
			connected.push_back(it->first);
			tree.insert(*it);
		}
		else {
			connected.push_back(it->first);
			connected.push_back(it->second);
			tree.insert(*it);
		}
	}

	connected.clear();




	return returnval;
}
