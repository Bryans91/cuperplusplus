#include "stdafx.h"
#include "HealPotion.h"
#include "Player.h"


HealPotion::HealPotion()
{
	itemDescription = "Healing potion";
}

HealPotion::~HealPotion()
{
}

std::string HealPotion::use(Player* p) {
	useString = "Used healing potion that heals you for 10 HP";
	p->heal(10);
	return useString;
}
