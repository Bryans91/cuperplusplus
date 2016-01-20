#pragma once
#include "Trap.h"
class Kebab :
	public Trap
{
public:
	Kebab();
	~Kebab();
	virtual void activate(Player * p);
	virtual const char * getText();
};

