#pragma once
#include "Useable.h"
class RandomPotion :
	public Useable
{
public:
	RandomPotion();
	RandomPotion(int power);
	~RandomPotion();
	virtual std::string use(Player* p);
	int usePower = 0;
	std::string save(ItemVisitor v);
};

