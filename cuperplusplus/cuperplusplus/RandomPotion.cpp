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

std::string RandomPotion::use(Player* p) {
	useString = "Used a potion that gave you " + usePower;
	switch (DungeonGenerator::RandomNumberGenerator(1, 4)){
	case 1:
		p->heal(usePower);
		useString += " health";
		break;
	case 2:
		p->damage(usePower);
		useString += " damage";
		break;
	case 3:
		p->increasePwr(usePower);
		useString += " attack power.";
		break;
	case 4:
		p->increaseDefence(usePower); 
		useString += " defence power.";
		break;
	default:
		break;
	}
	return useString;
}