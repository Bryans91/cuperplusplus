#pragma once
#include "Useable.h"
class RandomPotion :
	public Useable
{
public:
	RandomPotion();
	~RandomPotion();
	virtual std::string use(Player* p);
	int usePower = 0;
};

