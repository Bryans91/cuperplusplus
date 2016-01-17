#pragma once
#include "Trap.h"
class FakeButton :
	public Trap
{
public:
	FakeButton();
	~FakeButton();
	virtual const char * getText();
};

