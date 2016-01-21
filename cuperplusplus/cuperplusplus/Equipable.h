#pragma once
#include "Item.h"
class Equipable :
	public Item
{
public:
	Equipable();
	Equipable(Player* p);
	~Equipable();
	virtual void equip() {
		equipped = true;
	};
	virtual bool isEquipped() {
		return equipped;
	};
	virtual void unEquip() {
		equipped = false;
	};
protected:
	bool equipped = false;

};

