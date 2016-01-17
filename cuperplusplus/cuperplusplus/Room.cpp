#pragma once
#include "stdafx.h"
#include "Room.h"
#include "DungeonGenerator.h"
#include "Enemy.h"

static const char * sizeStrings[] = { "small", "medium", "large" };
static const char * stateStrings[] = { "neat", "dirty" };
static const char * furnitureStrings[] = { "There is a table with four chairs in this room.", "There is a bed in the corner.", "There is nothing in this room." };
static const char * lightStrings[] = { "In the room there burns a single candle which lights the room a bit.", "On the wall there is a torch, which lights the room.", "On the side there is a big fireplace which fills the room with light." };
static const char * discoveredTrapStrings[] = { "You find a tripwire that leads into the wall, in the wall there are holes cut out. You carefully step over the tripwire so that you don't activate it.", "You find a button that says free cake and decide to look what it leads to before you press it. You find out it was a trap and that the cake was a lie.", "You don't see any traps in this room." };
static const char * trapStrings[] = { "You trip over a tripwire and with your quick reflexes you manage to dodge the spikes that appear from the holes in the wall to your left. The bad thing is that there were also spikes coming from the right. Hp -10.", "You see a button that says free cake and immedietly press it, suddenly you smell a weird scent. You wake up with a slight headache and blurred sight. attackPower-3", "You don't see any traps in this room." };

Room::Room(){
	//Size switch
	switch (DungeonGenerator::RandomNumberGenerator(1, 3)){
	case 1: size = Size::SMALL;
		break;
	case 2: size = Size::MEDIUM;
		break;
	case 3: size = Size::LARGE;
		break;
	default: size = Size::MEDIUM;
		break;
	}
	// State switch
	switch (DungeonGenerator::RandomNumberGenerator(1, 2)){
	case 1: state = State::NEAT;
		break;
	case 2: state = State::DIRTY;
		break;
	default: state = State::NEAT;
		break;
	}
	//Furniture switch
	switch (DungeonGenerator::RandomNumberGenerator(1, 3)){
	case 1: furniture = Furniture::TABLE;
		break;
	case 2: furniture = Furniture::BED;
		break;
	case 3: furniture = Furniture::EMPTY;
		break;
	default: furniture = Furniture::EMPTY;
		break;
	}
	//Lighting switch
	switch (DungeonGenerator::RandomNumberGenerator(1, 3)){
	case 1: lighting = Lighting::CANDLE;
		break;
	case 2: lighting = Lighting::TORCH;
		break;
	case 3: lighting = Lighting::FIRE;
		break;
	default: lighting = Lighting::TORCH;
		break;
	}
	//Trap switch
	switch (DungeonGenerator::RandomNumberGenerator(1, 10)) {
	case 1: trap = Trap::TRIPWIRE;
		break;
	case 2: trap = Trap::FAKEBUTTON;
		break;
	default: trap = Trap::NONE;
		break;
	}
}

const char * Room::getTextForSize(){
	return sizeStrings[size];
}

const char * Room::getTextForState(){
	return stateStrings[state];
}

const char * Room::getTextForFurniture(){
	return furnitureStrings[furniture];
}

const char * Room::getTextForLighting(){
	return  lightStrings[lighting];
}

const char * Room::getTextForTrap() {
	if (DungeonGenerator::RandomNumberGenerator(1, 100) <= 80) {
		return  discoveredTrapStrings[trap];
	}
	else {
		trap = Trap();
		return  trapStrings[trap];
	}
}

std::map<Direction, Room*> Room::getAdjacentRooms() {
	return adjacentRooms;
}

std::list<std::string> Room::getPossibleActions() {
	return std::list < std::string > {"Run", "Fight", "Inv", "Stats", "Quit"};
}

Room::~Room(){
	enemies.clear();
	for (auto it = adjacentRooms.cbegin(); it != adjacentRooms.cend();){
		adjacentRooms.erase(it++);
	}
}

std::string Room::getRoomInfo(){
	std::string temp(getTextForSize());
	std::string allInfo = "You enter a " + temp + ", ";
	temp = getTextForState();
	allInfo += temp + " room. ";
	temp = getTextForFurniture();
	allInfo += temp + " ";
	temp = getTextForLighting();
	allInfo += temp + " ";
	temp = getTextForTrap();
	allInfo += temp + " \n";
	allInfo += getEnemyInfo(false);
	return allInfo;
}

void Room::addAdjacentRoom(Direction d, Room* r){
	adjacentRooms.insert(std::pair<Direction, Room*>(d,r));
}

void Room::addEnemy(Enemy* e){
	enemies.push_back(e);
	e->setCurrentRoom(this);
}

std::string Room::getEnemyInfo(bool fighting){
	std::string info, temp;
	if (enemies.size() != 0){
		int living = 0;

		temp = "";
		for (int i = 0; i < enemies.size(); i++){
			if (enemies[i]->checkAlive()){
				living++;
				if (fighting){
					temp += "Enemy " + std::to_string(i + 1) + "\n";
				}
				temp += enemies[i]->getStatus() + "\n\n";
			}
		}
		if (living != 0){
			if (!fighting){
				info += "This room has " + std::to_string(living) + " enemies. \n\n";
			}
			info += temp;
		}
	}
	return info;
}

bool Room::AttackEnemy(int no, Character* c){
	if (enemies[no - 1] != nullptr){
		c->attack(enemies[no - 1]);
		return true;
	}
	else {
		return false;
	}
}

void Room::EnemiesAttack(Character* c){
	for (int i = 0; i < enemies.size(); i++){
		enemies[i]->attack(c);
	}
}

bool Room::hasEnemies(){
	if (enemies.size() == 0){
		return false;
	}
	else{
		for (int i = 0; i < enemies.size(); i++){
			if (enemies[i]->checkAlive()){
				return true;
			}
		}
		return false;
	}
}