#pragma once
#include "Item.h"
class Equipable :
	public Item
{
public:
	Equipable();
	~Equipable();
	virtual std::string equip(Player* p) {
		equipped = true;
		return effectString;
	};
	virtual bool isEquipped() {
		return equipped;
	};
	virtual std::string unEquip(Player* p) {
		equipped = false;
		return negativeEffectString;
	};
protected:
	bool equipped = false;
	int equipPower = 0;
	virtual void getRandomName();
	std::string effectString = "";
	std::string negativeEffectString = "";

};

