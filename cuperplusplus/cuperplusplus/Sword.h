#pragma once
#include "Equipable.h"
class Sword :
	public Equipable
{
public:
	Sword();
	Sword(int power);
	~Sword();
	virtual std::string equip(Player* p);
	virtual std::string unEquip(Player* p);
	std::string save(ItemVisitor v);
};

