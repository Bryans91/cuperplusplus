#include "stdafx.h"
#include "ItemVisitor.h"
#include "Sword.h"
#include "Shield.h"
#include "HealPotion.h"
#include "RandomPotion.h"
#include "Item.h"


ItemVisitor::ItemVisitor()
{
}


ItemVisitor::~ItemVisitor()
{
}

//std::string ItemVisitor::Visit(Item* i){
//	return "Normal Item :(\n";
//}

std::string ItemVisitor::Visit(Sword* i)
{
	std::string retString;
	retString += "Type: Sword\n";
	retString += "Power: " + std::to_string(i->getEquipPower()) + "\n";
	return retString;
}
std::string ItemVisitor::Visit(Shield* i)
{
	std::string retString;
	retString += "Type: Shield\n";
	retString += "Power: " + std::to_string(i->getEquipPower()) + "\n";
	return retString;
}
std::string ItemVisitor::Visit(HealPotion* i)
{
	std::string retString;
	retString += "Type: HealPotion\n";
	return retString;
}
std::string ItemVisitor::Visit(RandomPotion* i)
{
	std::string retString;
	retString += "Type: RandomPotion\n";
	retString += "Power: " + std::to_string(i->usePower) + "\n";
	return retString;
}