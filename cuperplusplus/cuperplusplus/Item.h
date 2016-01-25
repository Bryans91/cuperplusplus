#pragma once
#include <string>
class Player;
class Item
{
public:
	Item();
	~Item();
	virtual void find(Player* p);
	virtual const char * getText();
protected:
	const char * itemDescription;

};

