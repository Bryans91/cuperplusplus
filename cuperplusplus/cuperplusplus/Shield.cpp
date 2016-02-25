#include "stdafx.h"
#include "Shield.h"
#include "Player.h"

Shield::Shield()
{
	getRandomName();
	itemDescription += " shield";
}

Shield::Shield(int power){
	setPower(power);
	itemDescription += " shield";
}
//increases defencepower

Shield::~Shield()
{
}

std::string Shield::equip(Player* p) 
{
	p->equip(this);
	return effectString;
}

std::string Shield::unEquip(Player * p)
{
	p->increaseDefence(-equipPower);
	equipped = false;
	return negativeEffectString;
}

std::string Shield::save(ItemVisitor v){
	return v.Visit(this);
}