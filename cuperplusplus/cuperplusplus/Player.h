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
#include "Talisman.h"
#include "Grenade.h"

class Player : public Character
{
private:
	int experience;
	std::map<int, int> ExperienceMap;
	double getExperienceNeeded(int);
	int unspendPoints = 0;
	void lvlup();
	std::vector<Item*> items;
	Shield* shield;
	Sword* sword;
	Talisman* talisman = new Talisman();
	Grenade* grenade = new Grenade();
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
	virtual void equip(Shield* s);
	virtual void equip(Sword* s);
	Sword* getSword(){ return sword; }
	Shield* getShield(){ return shield; }
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
	bool hasItems();
	void equipAllItems();
	void unEquipAllItems();
	void useAllRandomPotions();
	void useAllHealPotions();
	int hit(int dmg);
	int useTalisman(Room* s, Room* e){
		return talisman->shortestPath(s, e);
	}
	int useGrenade(Room* s, Room* e) {
		return grenade->shortestPath(s, e);
	}


};

