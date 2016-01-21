#pragma once
#include "Item.h"
class Useable :
	public Item
{
public:
	Useable();
	~Useable();
	virtual void use(Player * p);
protected:
};

