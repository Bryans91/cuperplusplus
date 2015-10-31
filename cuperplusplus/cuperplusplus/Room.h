#pragma once
#include "list"
#include "string"
#include <vector>
#include "Enemy.h"

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
	
	void addEnemy(Enemy* e);
	void addAdjacentRoom(Direction d, Room* r);
	
private:
	Size size;
	State state;
	Furniture furniture;
	Lighting lighting;
	std::map<Direction, Room*> adjacentRooms;
	std::vector<Enemy*> enemies;
	const char * getTextForSize();
	const char * getTextForState();
	const char * getTextForFurniture();
	const char * getTextForLighting();

};
