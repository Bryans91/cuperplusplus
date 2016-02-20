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
	std::vector<Item*> items;
	Room* currentRoom;

public:
	Character();
	~Character();
	int getHp(){ return healthPoints; };
	int getPwr(){ return attackPower; };
	int getDefence(){ return defencePower; };
	void setHP(int hp){ healthPoints = hp; };
	void setPwr(int p){ attackPower = p; };
	void setDefence(int d){ defencePower = d; };
	void setLevel(int l){ level = l; };
	void setMaxHP(int mhp){ maxHealthPoints = mhp; }

	void increaseHp(int pHp){ maxHealthPoints += pHp; };
	void increasePwr(int pAtk){
		attackPower += pAtk;
		if (attackPower < 5) {
			attackPower = 5;
		}
	};
	void increaseDefence(int pDef){
		defencePower += pDef;  
		if (defencePower < 5) {
			defencePower = 5;
		};
	};

	std::string getName() const { return name; }
	std::string getStatus();
	void setCreature();
	int hit(int dmg);
	void heal(int amount){
		healthPoints += amount; 
		if (healthPoints > maxHealthPoints) {
			healthPoints = maxHealthPoints;
		}
	};
	void damage(int amount) {
		healthPoints = (healthPoints - amount);
	};
	bool isFullyRestored(){ return (healthPoints == maxHealthPoints); };
	bool checkAlive(){ return (healthPoints > 0); };

	virtual void setCurrentRoom(Room* r);
	virtual Room* getCurrentRoom();

	virtual void attack(Character*);
};


