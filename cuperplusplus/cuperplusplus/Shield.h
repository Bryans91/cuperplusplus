#pragma once
#include "Equipable.h"
class Shield :
	public Equipable
{
public:
	Shield();
	Shield(int power);
	~Shield();
	virtual std::string equip(Player* p);
	virtual std::string unEquip(Player* p);
	std::string save(ItemVisitor v);
};

