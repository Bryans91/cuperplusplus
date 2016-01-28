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

void HealPotion::use(Player* p) {
	itemDescription = "Used healing potion that heals you for 10 HP";
	p->heal(10);
}
