#pragma once
#include "map"
#include "list"
#include "string"
#include "vector"
#include "Map.h"
#include "Enemy.h"
#include "Room.h"
#include "Character.h"
#include <iostream>

class Player : public Character
{
private:
	Room *currentRoom;
	int experience;
	std::map<int, int> ExperienceMap;
	double getExperienceNeeded(int);
	int unspendPoints = 0;
	void lvlup();
	std::vector<Item*> items;
	Equipable* shield = nullptr;
	Equipable* sword = nullptr;
public:
	Player(std::string aName);//, Map *map
	~Player();
	void goDirection(std::string);
	enum Action
	{
		eflee = 1,
		efight = 2,
		esearch = 3,
		erest = 4,
		echeckMap = 5,
		estats = 6,
		esave = 7,
		eAdmin = 8
	};

	Action chooseAction();
	void equip(Shield* s);
	void equip(Sword* s);
	Equipable* getSword(){ return sword; }
	Equipable* getShield(){ return shield; }
	void fight();
	void flee();
	void search();
	void loot(std::list<Enemy*> enemies);
	void rest();
	void stats();
	void cheat(Map *map);
	void attack(Character*);
	void save();
	void load(std::string playerName);
	std::string getStatus();
	int getUnspendPoints(){ return unspendPoints; };
	void LoadFromString(std::string);
	void setExp(int exp){ experience = exp; }
	void takeItem(Item* i);
	void unEquipItem(int i);
	std::string useItem(Item* i);
	void removeItem(Item* i);
	std::vector<Item*> getItems();
	void equipAllItems();
	void unEquipAllItems();
	void useAllRandomPotions();
	void useAllHealPotions();
	int hit(int dmg);


};

