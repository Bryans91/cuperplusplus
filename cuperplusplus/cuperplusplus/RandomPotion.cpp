#include "stdafx.h"
#include "RandomPotion.h"
#include "Player.h"
#include "DungeonGenerator.h"


RandomPotion::RandomPotion()
{
	itemDescription = "Random potion";
	usePower = DungeonGenerator::RandomNumberGenerator(-3, 5);
}
//random effect(use system as in room with the randomgenerator)

RandomPotion::~RandomPotion()
{
}

void RandomPotion::use(Player* p) {
	itemDescription = "Used a potion that gave you " + usePower;
	switch (DungeonGenerator::RandomNumberGenerator(1, 4)){
	case 1:
		p->heal(usePower);
		itemDescription += " health";
		break;
	case 2:
		p->damage(usePower);
		itemDescription += " damage";
		break;
	case 3:
		p->increasePwr(usePower);
		itemDescription += " attack power.";
		break;
	case 4:
		p->increaseDefence(usePower); 
		itemDescription += " defence power.";
		break;
	default:
		break;
	}

}
