#pragma once
#include "Item.h"
class Useable :
	public Item
{
public:
	Useable();
	virtual ~Useable();
	virtual std::string use(Player * p);
	virtual std::string save(ItemVisitor v) = 0;
protected:
	std::string useString = "";
};

