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
}
