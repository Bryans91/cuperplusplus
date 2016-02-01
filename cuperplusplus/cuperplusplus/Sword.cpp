#include "stdafx.h"
#include "Sword.h"
#include "Player.h"


Sword::Sword()
{
	getRandomName();
	itemDescription += " sword";
}
//increases attackpower


Sword::~Sword()
{
}

std::string Sword::equip(Player * p)
{
	p->increasePwr(equipPower);
	equipped = true;
	return effectString;
}

std::string Sword::unEquip(Player * p)
{
	p->increasePwr(-equipPower);
	equipped = false;
	return negativeEffectString;
}
