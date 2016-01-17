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
		if (getCurrentRoom()->getAdjacentRooms().count(Direction::NORTH) != 0) {
			setCurrentRoom(getCurrentRoom()->getAdjacentRooms().at(Direction::NORTH));
		}
	}
	else if (direction == "east") {
		if (getCurrentRoom()->getAdjacentRooms().count(Direction::EAST) != 0) {
			setCurrentRoom(getCurrentRoom()->getAdjacentRooms().at(Direction::EAST));
		}
	}
	else if (direction == "west") {
		if (getCurrentRoom()->getAdjacentRooms().count(Direction::WEST) != 0) {
			setCurrentRoom(getCurrentRoom()->getAdjacentRooms().at(Direction::WEST));
		}
	}
	else if (direction == "south") {
		if (getCurrentRoom()->getAdjacentRooms().count(Direction::SOUTH) != 0) {
			setCurrentRoom(getCurrentRoom()->getAdjacentRooms().at(Direction::SOUTH));
		}
	}
	getCurrentRoom()->Visited();
}


Player::~Player()
{
}