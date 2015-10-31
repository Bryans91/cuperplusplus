#pragma once
#include "list"
#include "string"
#include <vector>
#include "map"

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
	
	std::map<Direction, Room*> getAdjacentRooms();
	void addAdjacentRoom(Direction d, Room* r);
	inline std::string ToString(Direction d)
	{
		switch (d)
		{
		case Direction::NORTH: return "North";
		case Direction::EAST: return "East";
		case Direction::WEST: return "West";
		case Direction::SOUTH: return "South";
		default: return "MissingNo";
		}
	}
	
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
