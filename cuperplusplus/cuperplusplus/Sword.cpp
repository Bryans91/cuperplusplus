#include "stdafx.h"
#include "Sword.h"
#include "Player.h"


Sword::Sword()
{
	getRandomName();
	itemDescription += " sword";
}

Sword::Sword(int power){
	setPower(power);
	itemDescription += " sword";
}
//increases attackpower


Sword::~Sword()
{
}

//std::string Sword::equip(Player * p)
//{
//	p->increasePwr(equipPower);
//	equipped = true;
//	return effectString;
//}

std::string Sword::unEquip(Player * p)
{
	p->increasePwr(-equipPower);
	equipped = false;
	return negativeEffectString;
}

std::string Sword::save(ItemVisitor v){
	return v.Visit(this);
}

std::string Sword::equip(Player* p){
	p->equip(this);
	return effectString;
}