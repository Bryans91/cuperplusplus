#pragma once
#include "Trap.h"
class Tripwire :
	public Trap
{
public:
	Tripwire();
	~Tripwire();
	virtual void activate(Player * p);
	virtual const char * getText();
};

