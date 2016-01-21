#pragma once
#include "Useable.h"
class RandomPotion :
	public Useable
{
public:
	RandomPotion();
	~RandomPotion();
	virtual void use(Player* p);
};

