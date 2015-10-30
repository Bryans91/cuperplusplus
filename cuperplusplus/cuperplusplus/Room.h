#pragma once
#include "list"
#include "string"
#include <vector>
class Room
{
public:
	Room();
	~Room();
	std::list<std::string> getPossibleActions();

	enum Size
	{
		SMALL =1, MEDIUM = 2, LARGE = 3
	};

	enum State
	{
		NEAT = 1, DIRTY = 2
	};

	enum Furniture
	{
		TABLE = 1, BED = 2, EMPTY = 3
	};

	enum Lighting
	{
		CANDLE = 1, TORCH = 2, FIRE = 3
	};

private:
	Size size;
	State state;
	Furniture furniture;
	Lighting lighting;
	std::vector<Room> adjacentRooms;

};
