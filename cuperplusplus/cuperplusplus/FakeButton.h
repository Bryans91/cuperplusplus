#pragma once
#include "Trap.h"
class FakeButton :
	public Trap
{
public:
	FakeButton();
	~FakeButton();
	virtual void activate(Player * p);
	virtual const char * getText();
};

