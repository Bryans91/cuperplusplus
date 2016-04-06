#pragma once
#include "Item.h"
class NoItem :
	public Item
{
public:
	NoItem();
	~NoItem();
	std::string save(ItemVisitor iv);
};

