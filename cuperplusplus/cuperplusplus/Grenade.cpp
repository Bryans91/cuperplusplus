#include "stdafx.h"
#include "Grenade.h"
#include "Room.h"
#include "Player.h"
#include <queue>


Grenade::Grenade()
{
}


Grenade::~Grenade()
{
}

int Grenade::minSpanningTree(std::vector<Room*> rooms, Room* start) {
	int returnval = 0;
	bool allConnected = false;
	// individual distances need to be set.
	std::deque<Room*> q;
	std::vector<Room*> visited;
	std::vector<Room*> connected;
	std::map<Room*, int> distances;

	distances.insert(std::pair<Room*, int>(start, 0));

	q.push_back(start);

	while (!q.empty() && !allConnected) {
		Room* r = q.front();
		q.pop_front();

		visited.push_back(r);
		connected.push_back(r);

		for (std::pair<Direction, Room*> adj : r->getAdjacentRooms()) {
		}
	}
	q.clear();
	visited.clear();
	connected.clear();




	return returnval;
}
