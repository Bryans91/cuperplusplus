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

bool compare(const std::pair<std::pair<Room*, Room*>, int>&i, const std::pair<std::pair<Room*, Room*>, int>&j)
{
	return i.second < j.second;
}

std::vector<std::pair<Room*, Room*>> Grenade::sortByRoomWeigths(std::map<Room*, Room*> allConnectedRooms) {
	std::vector<std::pair<Room*, Room*>> sorted; 
	std::vector<std::pair<std::pair<Room*, Room*>, int>> sortingVector;
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
		sortingVector.push_back(std::make_pair(std::make_pair(it->first, it->second), weight));
	}
	std::sort(sortingVector.begin(), sortingVector.end(), compare);

	std::vector<std::pair<std::pair<Room*, Room*>, int>>::iterator it2 = sortingVector.begin();
	for (it2 = sortingVector.begin(); it2 != sortingVector.end(); ++it2) {
		sorted.push_back(it2->first);
	}
	return sorted;
}

int Grenade::minSpanningTree(std::map<Room*, Room*> allConnectedRooms) {

	std::vector<std::pair < Room*, Room* >> sortedRooms = sortByRoomWeigths(allConnectedRooms);
	int returnval = 0;
	// individual distances need to be set.
	std::vector<Room*> connected;
	std::vector<std::pair<Room*, Room*>> tree;
	std::vector<std::pair<Room*, Room*>>::iterator it = sortedRooms.begin();
	for (it = sortedRooms.begin(); it != sortedRooms.end(); ++it) {
		if (std::find(connected.begin(), connected.end(), it->first) != connected.end() && std::find(connected.begin(), connected.end(), it->second) != connected.end()) {
			//contains both rooms
			//collapsepath?
			break;
		}
		else if (std::find(connected.begin(), connected.end(), it->first) != connected.end()) {
			//contains first room
			connected.push_back(it->second);
			tree.push_back(std::pair<Room*, Room*>(it->first, it->second));
		}
		else if (std::find(connected.begin(), connected.end(), it->second) != connected.end()) {
			//contains second room
			connected.push_back(it->first);
			tree.push_back(std::pair<Room*, Room*>(it->first, it->second));
		}
		else {
			connected.push_back(it->first);
			connected.push_back(it->second);
			tree.push_back(std::pair<Room*, Room*>(it->first, it->second));
		}
	}

	connected.clear();




	return returnval;
}
