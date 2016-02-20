#pragma once
#include "stdafx.h"
#include "Character.h"


Character::Character()
{
}


int Character::hit(int dmg)
{
	if (!checkAlive()){
		return 0;
	}
	int dmgtodeal = dmg - defencePower;
	if (dmgtodeal < 0){
		dmgtodeal = 0;
	}
	healthPoints -= (dmgtodeal);
	if (healthPoints <= 0)
		healthPoints = 0;
	return dmgtodeal;
}


Character::~Character()
{
	currentRoom = NULL;
	for (int i = 0; i < items.size(); i++){
		delete items[i];
	}
	items.clear();
}

void Character::setCurrentRoom(Room* r){
	currentRoom = r;
}

Room* Character::getCurrentRoom(){
	return currentRoom;
}

std::string Character::getStatus(){
	std::string retString;
	retString += "Name:      " + this->name;
	retString += "\nLevel:     " + std::to_string(level);
	retString += "\nHitpoints: " + std::to_string(healthPoints);
	retString += "\nAttack:    " + std::to_string(attackPower);
	retString += "\nDefence:   " + std::to_string(defencePower);

	return retString;
}

void Character::attack(Character* c){
	c->hit(attackPower);
}