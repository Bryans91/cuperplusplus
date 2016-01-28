#pragma once
#include "Equipable.h"
class Shield :
	public Equipable
{
public:
	Shield();
	~Shield();
	virtual void equip(Player* p);
	virtual void unEquip(Player* p);
};

