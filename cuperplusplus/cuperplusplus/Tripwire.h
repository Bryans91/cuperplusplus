#pragma once
#include "Trap.h"
class Tripwire :
	public Trap
{
public:
	Tripwire();
	~Tripwire();
	virtual const char * getText();
};

