#pragma once
#include "Item.h"
class Useable :
	public Item
{
public:
	Useable(Player * p);
	Useable();
	~Useable();
	virtual void use();
protected:
};

