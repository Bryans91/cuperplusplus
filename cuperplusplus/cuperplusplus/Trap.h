#pragma once
class Trap
{
public:
	Trap();
	~Trap();
	virtual const char * getText();
protected:
	bool dismantled;
	int discoverChance;
	bool discoverTrap();
};

