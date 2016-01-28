#include "stdafx.h"
#include "Shield.h"
#include "Player.h"

Shield::Shield()
{
	getRandomName();
	itemDescription += " shield";
}
//increases defencepower

Shield::~Shield()
{
}

void Shield::equip(Player* p) {

}