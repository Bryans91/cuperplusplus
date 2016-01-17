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

void Player::attack(Character* c){
	experience += c->hit(attackPower);
}

std::string Player::getStatus(){
	std::string retString;
	retString += "Name:         " + this->name;
	retString += "\nLevel:        " + std::to_string(level);
	retString += "\nHitpoints:    " + std::to_string(healthPoints);
	retString += "\nAttack:       " + std::to_string(attackPower);
	retString += "\nDefence:      " + std::to_string(defencePower);
	retString += "\nExperience:   " + std::to_string(experience);
	retString += "\nExp to lvlup: need to calculate this.";

	return retString;
}