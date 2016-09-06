#pragma once
#include "stdafx.h"
#include "Room.h"
#include "DungeonGenerator.h"
#include "Enemy.h"

static const char * sizeStrings[] = { "small", "medium", "large" };
static const char * stateStrings[] = { "neat", "dirty" };
static const char * furnitureStrings[] = { "There is a table with four chairs in this room.", "There is a bed in the corner.", "There is nothing in this room." };
static const char * lightStrings[] = { "In the room there burns a single candle which lights the room a bit.", "On the wall there is a torch, which lights the room.", "On the side there is a big fireplace which fills the room with light." };
static const char * itemString = "";
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
	switch (DungeonGenerator::RandomNumberGenerator(1, 20)) {
	case 1: trap = new Tripwire();
		break;
	case 2: trap = new FakeButton();
		break;
	case 3: trap = new Beer();
		break;
	case 4: trap = new Kebab();
		break;
	default: trap = noTrap;
		break;
	}
	//Item switch
	switch (DungeonGenerator::RandomNumberGenerator(1, 12)) {
	case 1: item = new Sword();
		break;
	case 2: item = new Shield();
		break;
	case 3: item = new HealPotion();
		break;
	case 4: item = new RandomPotion();
		break;
	default: item = noItem;
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
	return trap->getText();
}

std::string Room::getTextForItem() {
	return item->getText();
}

void Room::checkForTraps(Player* p) {
	trap->activate(p);
}

void Room::checkForItems() {
	Utils::PrintLine("You find a " + getTextForItem() + " hidden under a layer of dust. Take it or leave it?\n|  Take  |  Leave  |");
}

Item* Room::getItem() {
	if (!hasItem()) {
		return nullptr;
	}
	else {
		return item;
	}
}

void Room::removeItem() {
	item = noItem;
}

std::map<Direction, Room*> Room::getAdjacentRooms() {
	return adjacentRooms;
}

std::list<std::string> Room::getPossibleActions() {
	if (item != noItem) {
		itemString = "Item";
	}
	else {
		itemString = "";
	}
	return std::list < std::string > {"Run", "Fight", "Inv", "Stats", "Rest", "Save", itemString};
}

Room::~Room(){
	if (noTrap != trap){
		delete noTrap;
	}
	noTrap = NULL;
	if (noItem != item){
		delete noItem;
	}
	noItem = NULL;

	delete trap;
	trap = NULL;

	delete item;
	item = NULL;
	for (int i = 0; i < enemies.size(); i++){
		delete enemies[i];
	}

	enemies.clear();
	adjacentRooms.clear();



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
	if (d == null){
		for (std::map<Direction, Room*>::iterator it = oldRooms.begin(); it != oldRooms.end(); ++it){
			if (it->second == r){
				adjacentRooms.insert(std::pair<Direction, Room*>(it->first, r));
			}
		}
		
	}
	else {
		adjacentRooms.insert(std::pair<Direction, Room*>(d, r));
	}

}

void Room::clearRooms(){
	oldRooms = adjacentRooms;
	adjacentRooms.clear();
}

void Room::addCollapsedRoom(Room* r){
	for (std::map<Direction, Room*>::iterator it = oldRooms.begin(); it != oldRooms.end(); ++it){
		if (it->second == r){
			collapsedRooms.insert(std::pair<Direction, Room*>(it->first, r));
		}
	}

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
	if (no == 0){
		for (int i = 0; i < enemies.size(); i++){
			if (enemies[i]->checkAlive()){
				c->attack(enemies[i]);
				return true;
			}
		}
	}
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

int Room::hasEnemies(){
	int enemyCount = 0;
	for (int i = 0; i < enemies.size(); i++){
		if (enemies[i]->checkAlive()){
			enemyCount++;
		}
	}
	return enemyCount;
}