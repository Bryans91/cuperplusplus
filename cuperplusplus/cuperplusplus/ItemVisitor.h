#pragma once
#include<string>
class Sword;
class Shield;
class HealPotion;
class RandomPotion;
class Item;
class ItemVisitor
{
public:
	ItemVisitor();
	~ItemVisitor();
	//std::string Visit(Item*);
	std::string Visit(Sword*);
	std::string Visit(Shield*);
	std::string Visit(HealPotion*);
	std::string Visit(RandomPotion*);
};

