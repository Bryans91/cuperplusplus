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
		itemDescription = "elven";
		equipPower = 8;
		break;
	default:
		itemDescription = "normal";
		equipPower = 4;
		break;
	}
}