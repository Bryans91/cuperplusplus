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
	virtual void unEquip(Player* p) {
		equipped = false;
	};
protected:
	bool equipped = false;
	int equipPower = 0;
	virtual void getRandomName();

};

