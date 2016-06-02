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

std::map<Room*, Room*> Grenade::sortByRoomWeigths(std::map<Room*, Room*> allConnectedRooms) {
	std::map<Room*, Room*> sorted;
	std::map<std::map< Room*, Room* >, int > sortingMap;
	std::map<Room*, Room*>::iterator it = allConnectedRooms.begin();
	int weight = 0;
	for (it = allConnectedRooms.begin(); it != allConnectedRooms.end(); ++it) {
		weight = 0;
		if (it->first->hasEnemies()) {
			weight++;
		}
		if (it->second->hasEnemies()) {
			weight++;
		}
		if (it->first->hasTrap()) {
			weight++;
		}
		if (it->second->hasTrap()) {
			weight++;
		}
		sortingMap[it->first][it->second] = weigth;
	}
}

int Grenade::minSpanningTree(std::map<Room*, Room*> allConnectedRooms) {
	allConnectedRooms = sortByRoomWeigths(allConnectedRooms);
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
