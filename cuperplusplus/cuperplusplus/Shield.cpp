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

std::string Shield::equip(Player* p) 
{
	p->increaseDefence(equipPower);
	equipped = true;
	return effectString;
}

std::string Shield::unEquip(Player * p)
{
	p->increaseDefence(-equipPower);
	equipped = false;
	return negativeEffectString;
}