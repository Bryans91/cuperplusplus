#pragma once
#include "Useable.h"
class HealPotion :
	public Useable
{
public:
	HealPotion();
	~HealPotion();
	virtual void use(Player* p);
};

