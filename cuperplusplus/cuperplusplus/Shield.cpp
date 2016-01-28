#include "stdafx.h"
#include "Shield.h"
#include "Player.h"

Shield::Shield()
{
	getRandomName();
	itemDescription += " shield";
}
//increases defencepower

Shield::~Shield()
{
}

void Shield::equip(Player* p) 
{
	p->increaseDefence(equipPower);
	equipped = true;
}

void Sword::unEquip(Player * p)
{
	p->increaseDefence(-equipPower);
	equipped = false;
}