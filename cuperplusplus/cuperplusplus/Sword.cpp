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

void Sword::equip(Player * p)
{
	p->increasePwr(equipPower);
	equipped = true;
}

void Sword::unEquip(Player * p) 
{
	p->increasePwr(-equipPower);
	equipped = false;
}
