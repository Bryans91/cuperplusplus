#pragma once
#include "Useable.h"
class HealPotion :
	public Useable
{
public:
	HealPotion();
	~HealPotion();
	virtual std::string use(Player* p);
};

