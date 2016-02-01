#pragma once
#include "Item.h"
class Useable :
	public Item
{
public:
	Useable();
	~Useable();
	virtual std::string use(Player * p);
protected:
	std::string useString = "";
};

