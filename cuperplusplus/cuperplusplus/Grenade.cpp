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

std::vector<std::pair<Room*, Room*>> Grenade::sortByRoomWeigths(std::vector<std::pair<Room*, Room*>> allConnectedRooms) {
	std::vector<std::pair<Room*, Room*>> sorted; 
	std::vector<std::pair<std::pair<Room*, Room*>, int>> sortingVector;
	std::vector<std::pair<Room*, Room*>>::iterator it = allConnectedRooms.begin();
	int weight = 0;
	for (it; it != allConnectedRooms.end(); ++it) {
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

int Grenade::minSpanningTree(DungeonLayer* old) {
	//std::vector<std::pair<Room*, Room*>> sortedRooms = old->getConnectedRooms();
	std::vector<std::pair < Room*, Room* >> sortedRooms = sortByRoomWeigths(old->getConnectedRooms());
	old->removeRoomConnections();
	Talisman* t = new Talisman();

	int returnval = 0;
	// individual distances need to be set.
	// remove all connections, then rebuild the layer.

	std::vector<std::pair<Room*, Room*>>::iterator it = sortedRooms.begin();
	for (it = sortedRooms.begin(); it != sortedRooms.end(); ++it) {
		int path = t->shortestPath(it->first, it->second);
		if (path != 0){//
			it->first->addCollapsedRoom(it->second);
			it->second->addCollapsedRoom(it->first);

		}
		else {
			it->first->addAdjacentRoom(null, it->second);
			it->second->addAdjacentRoom(null, it->first);
			//add connection
		}


	}


	delete t;



	return returnval;
}
