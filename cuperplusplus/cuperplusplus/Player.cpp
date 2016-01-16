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

void Player::goDirection(std::string direction){
	if (direction == "north") {
		if (getCurrentRoom()->getAdjacentRooms().find(Direction::NORTH)->second != NULL) {
			setCurrentRoom(getCurrentRoom()->getAdjacentRooms().find(Direction::NORTH)->second);
		}
	}
	else if (direction == "east") {
		if (getCurrentRoom()->getAdjacentRooms().find(Direction::EAST)->second != NULL) {
			setCurrentRoom(getCurrentRoom()->getAdjacentRooms().find(Direction::EAST)->second);
		}
	}
	else if (direction == "west") {
		if (getCurrentRoom()->getAdjacentRooms().find(Direction::WEST)->second != NULL) {
			setCurrentRoom(getCurrentRoom()->getAdjacentRooms().find(Direction::WEST)->second);
		}
	}
	else if (direction == "south") {
		if (getCurrentRoom()->getAdjacentRooms().find(Direction::SOUTH)->second != NULL) {
			setCurrentRoom(getCurrentRoom()->getAdjacentRooms().find(Direction::SOUTH)->second);
		}
	}
	getCurrentRoom()->Visited();
}


Player::~Player()
{
}