#include "stdafx.h"
#include "Equipable.h"
#include "Player.h"
#include "DungeonGenerator.h"


Equipable::Equipable()
{
}

Equipable::~Equipable()
{
}

void Equipable::getRandomName() {
	switch (DungeonGenerator::RandomNumberGenerator(1, 4)){
	case 1:
		itemDescription = "crude";
		equipPower = 3;
		break;
	case 2:
		itemDescription = "decent";
		equipPower = 5;
		break;
	case 3:
		itemDescription = "crystal";
		equipPower = 7;
		break;
	default:
		itemDescription = "normal";
		equipPower = 4;
		break;
	}
}

void Equipable::setPower(int p){
	equipPower = p;
	switch (p){
	case 3:
		itemDescription = "crude";
		break;
	case 4:
		itemDescription = "normal";
		break;
	case 5:
		itemDescription = "decent";
		break;
	case 7:
		itemDescription = "crystal";
		break;
	default:
		itemDescription = "normal";
		equipPower = 4;
		break;
	}

}


std::string Equipable::equip(Player* p){
	return "";
}
//std::string Equipable::save(ItemVisitor v){
//	return v.Visit(this);
//}

