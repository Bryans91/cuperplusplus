#pragma once
#include "stdafx.h"
#include "Character.h"


Character::Character()
{
}


bool Character::hit(int dmg)
{
	if (!checkAlive())
		return !checkAlive();
	healthPoints -= dmg;
	if (healthPoints <= 0)
		healthPoints = 0;
	return !checkAlive();
}


Character::~Character()
{
}
