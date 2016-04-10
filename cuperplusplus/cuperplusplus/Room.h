#pragma once
#include "list"
#include "string"
#include <vector>
#include <map>
#include "Trap.h"
#include "Tripwire.h"
#include "FakeButton.h"
#include "Beer.h"
#include "Kebab.h"
#include "Item.h"
#include "HealPotion.h"
#include "RandomPotion.h"
#include "Sword.h"
#include "Shield.h"
#include "NoItem.h"

class Enemy;
class Character;



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
	std::string getEnemyInfo(bool);
	void addEnemy(Enemy* e);
	std::map<Direction, Room*> getAdjacentRooms();
	std::map<Direction, Room*> getCollapsedRooms(){
		return collapsedRooms;
	}
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
	};
	void Visited(){ visited = true; };
	bool isVisited(){ return visited; };
	int hasEnemies();
	bool AttackEnemy(int, Character*);
	bool hasItem(){
		if (item != noItem) { return true; }
		else { return false; }
	};
	void EnemiesAttack(Character* c);
	void checkForTraps(Player * p);
	void checkForItems();
	void removeItem();
	Item* getItem();
	Item* getNoItem() {
		return noItem;
	};
	
private:
	Size size;
	State state;
	Furniture furniture;
	Lighting lighting;
	Trap* trap;
	Trap* noTrap = new Trap();
	Item* item;
	Item* noItem = new NoItem();
	std::map<Direction, Room*> adjacentRooms;
	std::map<Direction, Room*> collapsedRooms;
	std::vector<Enemy*> enemies;
	bool visited = false;
	const char * getTextForSize();
	const char * getTextForState();
	const char * getTextForFurniture();
	const char * getTextForLighting();
	const char * getTextForTrap();
	std::string getTextForItem();



};