#pragma once
#include "stdafx.h"
#include "Player.h"

Player::Player(std::string aName)
{
	maxHealthPoints = healthPoints = 50;
	defencePower = 10;
	attackPower = 5;

	level = 1;
	experience = 0;
	name = aName;

	//Add items with:
	//items.push_back();
}


Player::~Player()
{
}