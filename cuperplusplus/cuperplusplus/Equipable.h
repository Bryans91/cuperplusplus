#pragma once
#include "Item.h"
class Equipable :
	public Item
{
public:
	Equipable();
	~Equipable();
	virtual void equip(Player* p) {
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

