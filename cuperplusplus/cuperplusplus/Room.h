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
		SMALL, MEDIUM, LARGE
	};

	enum State
	{
		NEAT, DIRTY
	};

	enum Furniture
	{
		TABLE, BED, EMPTY
	};

	enum Lighting
	{
		CANDLE, TORCH, FIRE
	};

private:
	Size size;
	State state;
	Furniture furniture;
	Lighting lighting;
	std::vector<Room> adjacentRooms;

};
