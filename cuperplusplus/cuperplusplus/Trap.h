#pragma once
class Player;
class Trap
{
public:
	Trap();
	~Trap();
	virtual const char * getText();
	virtual void activate(Player* p);
protected:
	bool dismantled;
	int discoverChance;
	bool discoverTrap();
};

