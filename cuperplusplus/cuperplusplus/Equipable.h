#pragma once
#include "Item.h"
class Equipable :
	public Item
{
public:
	Equipable();
	virtual ~Equipable();
	virtual std::string equip(Player* p);
	virtual bool isEquipped() {
		return equipped;
	};
	virtual std::string unEquip(Player* p) {
		equipped = false;
		return negativeEffectString;
	};
	virtual int getEquipPower(){ return equipPower; }
	virtual std::string save(ItemVisitor v) = 0;
	virtual void setPower(int p);
protected:
	bool equipped = false;
	int equipPower = 0;
	virtual void getRandomName();
	std::string effectString = "";
	std::string negativeEffectString = "";

};

