#include "stdafx.h"
#include "Talisman.h"
#include "Room.h"
#include "Player.h"
#include <queue>
#include <vector>


Talisman::Talisman()
{
}


Talisman::~Talisman()
{
}

int Talisman::shortestPath(Room* stairs, Room* start){
	int returnval = 0;
	bool found = false;
	// individual distances need to be set.
	std::deque<Room*> q;
	std::vector<Room*> visited;
	std::map<Room*, int> distances;

	distances.insert(std::pair<Room*,int>(start, 0));

	q.push_back(start);

	while (!q.empty() && !found){
		Room* r = q.front();
		q.pop_front();

		visited.push_back(r);

		for (std::pair<Direction, Room*> adj : r->getAdjacentRooms()){
			bool inQ = find(q.begin(), q.end(), adj.second) != q.end();
			bool roomVisited = find(visited.begin(), visited.end(), adj.second) != visited.end();

			if (!inQ && !roomVisited){
				distances.insert(std::pair<Room*, int>(adj.second, distances.at(r)+1));
				if (adj.second == stairs){
					returnval = distances.at(adj.second);
					found = true;
					break;
				}
				q.push_back(adj.second);
			}
		}
	}
	q.clear();
	visited.clear();




	return returnval;
}