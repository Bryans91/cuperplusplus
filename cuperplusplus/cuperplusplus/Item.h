#pragma once
#include <string>
class Player;
class Item
{
public:
	Item();
	virtual ~Item();
	virtual void find(Player* p);
	virtual std::string getText();
protected:
	std::string itemDescription = "";

};

