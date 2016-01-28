#pragma once
#include "Equipable.h"
class Sword :
	public Equipable
{
public:
	Sword();
	~Sword();
	virtual void equip(Player* p);
	virtual void unEquip(Player* p);
};

