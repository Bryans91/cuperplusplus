#pragma once
#include "Equipable.h"
class Sword :
	public Equipable
{
public:
	Sword();
	~Sword();
	virtual std::string equip(Player* p);
	virtual std::string unEquip(Player* p);
};

