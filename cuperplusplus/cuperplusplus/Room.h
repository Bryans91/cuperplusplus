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
	std::string getRoomInfo();
	
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
	void addAdjacentRoom(Room* r);

private:
	Size size;
	State state;
	Furniture furniture;
	Lighting lighting;
	std::vector<Room*> adjacentRooms;
	const char * getTextForSize();
	const char * getTextForState();
	const char * getTextForFurniture();
	const char * getTextForLighting();

};
