#pragma once
#include <string>
class Player;
#include "ItemVisitor.h";
class Item
{
public:
	Item();
	virtual ~Item();
	virtual void find(Player* p);
	virtual std::string getText();
	virtual std::string save(ItemVisitor v) = 0;
protected:
	std::string itemDescription = "";

};

