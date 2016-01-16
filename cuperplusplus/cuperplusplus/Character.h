#pragma once
#include "list"
#include "string"
#include "Item.h"
#include "Utils.h"
#include "Room.h"

class Character
{
protected:
	std::string name;
	int level;
	int healthPoints;
	int maxHealthPoints;
	int attackPower;
	int defencePower;
	std::list<Item *> items;
	Room* currentRoom;

public:
	Character();
	~Character();
	int getHp(){ return healthPoints; };
	int getPwr(){ return attackPower; };
	int getDefence(){ return defencePower; };

	void increaseHp(int pHp){ maxHealthPoints += pHp; };
	void increasePwr(int pAtk){ attackPower += pAtk; };
	void increaseDefence(int pDef){ defencePower += pDef; };

	std::string getName() const { return name; }
	std::string getStatus(){ return std::to_string(healthPoints) + "hp"; };
	void setCreature();
	bool hit(int dmg);
	void heal(int amount){
		healthPoints = (((healthPoints + amount) > maxHealthPoints) ? this->maxHealthPoints : (healthPoints + amount));
	};
	bool isFullyRestored(){ return (healthPoints == maxHealthPoints); }
	bool checkAlive(){ return (healthPoints > 0); }

	virtual void setCurrentRoom(Room* r);
	virtual Room* getCurrentRoom();
};


