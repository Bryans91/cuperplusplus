#pragma once
#include "list"
#include "string"
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

	enum Furnature
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
	Furnature furnature;
	Lighting lighting;
	std::vector<Room> adjacentRooms;

};
