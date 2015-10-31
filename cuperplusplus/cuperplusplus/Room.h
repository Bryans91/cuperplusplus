#pragma once
#include "list"
#include "string"
#include <vector>

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
enum Direction
{
	NORTH, EAST, SOUTH, WEST
};

class Room
{
public:


	Room();
	~Room();
	std::list<std::string> getPossibleActions();
	std::string getRoomInfo();
	

	void addAdjacentRoom(Direction d, Room* r);
	
private:
	Size size;
	State state;
	Furniture furniture;
	Lighting lighting;
	std::map<Direction, Room*> adjacentRooms;
	const char * getTextForSize();
	const char * getTextForState();
	const char * getTextForFurniture();
	const char * getTextForLighting();

};
