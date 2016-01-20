#pragma once
#include "Trap.h"
class Beer :
	public Trap
{
public:
	Beer();
	~Beer();
	virtual void activate(Player * p);
	virtual const char * getText();
};

