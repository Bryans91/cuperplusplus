#pragma once
#include "list"
#include "string"
#include "Item.h"

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
	void heal(int ammount){
		healthPoints = (((healthPoints + ammount) > maxHealthPoints) ? this->maxHealthPoints : (healthPoints + ammount));
	};
	bool isFullyRestored(){ return (healthPoints == maxHealthPoints); }
	bool checkAlive(){ return (healthPoints > 0); };
};

};
