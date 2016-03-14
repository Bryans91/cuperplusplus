#pragma once
#include "stdafx.h"
#include "Player.h"
#include "ItemVisitor.h"

Player::Player(std::string aName)
{
	// load player from file if exists.
	maxHealthPoints = healthPoints = 50;
	defencePower = 5;
	attackPower = 5;

	level = 1;
	experience = 0;
	name = aName;
	ExperienceMap.insert(std::pair<int,int>(1,0));
	ExperienceMap.insert(std::pair<int,int>(2, 20));
	//Add items with:
	//items.push_back();
}

double Player::getExperienceNeeded(int level){
	if (ExperienceMap.find(level) == ExperienceMap.end()){
		int exp = std::round(getExperienceNeeded(level - 1) + (getExperienceNeeded(level - 1) - getExperienceNeeded(level - 2))*1.1);
		std::pair<int, int> exppair(level, exp);
		ExperienceMap.insert(exppair);
	}
	return ExperienceMap.find(level)->second;
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
	if (shield != nullptr){
		delete shield;
	}
	shield = NULL;
	if (sword != nullptr){
		delete sword;
	}
	sword = NULL;
	delete talisman;
	talisman = NULL;
}

void Player::attack(Character* c){
	experience += c->hit(attackPower);
	if (experience >= getExperienceNeeded(level+1)){
		lvlup();
	}
}

void Player::lvlup(){
	level++;
	//unspendPoints += 5; can do something with this later.
	increaseHp(10);
	heal(10);
	increaseDefence(1);
	increasePwr(2);
}

std::string Player::getStatus(){
	std::string retString;
	retString += "Name:         " + this->name;
	retString += "\nLevel:        " + std::to_string(level);
	retString += "\nHitpoints:    " + std::to_string(healthPoints) + "/" + std::to_string(maxHealthPoints);
	retString += "\nAttack:       " + std::to_string(attackPower) + " + " + std::to_string(sword != nullptr ? sword->getEquipPower() : 0);
	retString += "\nDefence:      " + std::to_string(defencePower) + " + " + std::to_string(shield != nullptr? shield->getEquipPower() : 0);
	retString += "\nExperience:   " + std::to_string(experience)   + "/" + std::to_string((int)getExperienceNeeded(level+1));


	return retString;
}

void Player::save(){
	std::string saveString;
	saveString += "Name: " + name;
	saveString += "\nLevel: " + std::to_string(level);
	saveString += "\nHitpoints: " + std::to_string(healthPoints);
	saveString += "\nMaxHitpoints: " + std::to_string(maxHealthPoints);
	saveString += "\nAttack: " + std::to_string(attackPower);
	saveString += "\nDefence: " + std::to_string(defencePower);
	saveString += "\nExperience: " + std::to_string(experience);
	// TODO add items and save those.
	saveString += "\n\nEquiped:";
	ItemVisitor iv = ItemVisitor();
	if (sword != nullptr){
		saveString += "\nSword:\n";
		saveString += sword->save(iv);
	}
	if (shield != nullptr){
		saveString += "\nShield:\n";
		saveString += shield->save(iv);
	}
	saveString += "\n\nItems:\n";
	for (int i = 0; i < items.size(); i++){
		saveString += items[i]->save(iv);
	}

	Utils::SaveFile(saveString, name);
}


void Player::takeItem(Item* i) {
	items.push_back(i);
}
void Player::equip(Sword* s){
	/*if (sword != NULL && sword != s){
		items.push_back(sword);
	}*/
	sword = s;
}

void Player::equip(Shield* s){
	/*if (shield != NULL && shield != s){
		items.push_back(shield);
	}*/
	shield = s;
}




void Player::unEquipItem(int i) {
	if (i == 1){
		items.push_back(sword);
		sword = nullptr;
	}
	else if (i == 2){
		items.push_back(shield);
		shield == nullptr;
	}
}

std::string Player::useItem(Item* i) {

	Useable* us = dynamic_cast<Useable*>(i);
	if (us != NULL) {
		return us->use(this);
	}
	else {
		Utils::PrintLine("This item isn't useable.");
		return "";
	}
}

std::vector<Item*> Player::getItems() {
	return items;
}

void Player::equipAllItems() {
	for each(Item* i in items)  {
		Equipable* eq = dynamic_cast<Equipable*>(i);
		if (eq != NULL) {
			eq->equip(this);
		}
	}
}

void Player::unEquipAllItems() {
	for each(Item* i in items)  {
		Equipable* eq = dynamic_cast<Equipable*>(i);
		if (eq != NULL) {
			eq->unEquip(this);
		}
	}
}

void Player::useAllRandomPotions() {
	for each(Item* i in items)  {
		if (RandomPotion* rp = (RandomPotion*)i) {
			rp->use(this);
		}
	}
}

void Player::useAllHealPotions() {
	for each(Item* i in items)  {
		if (HealPotion* hp = (HealPotion*)i) {
			hp->use(this);
		}
	}
}



void Player::removeItem(Item* i) {
	Equipable* eq = dynamic_cast<Equipable*>(i);
	if (eq != NULL) {
		eq->unEquip(this);
	}
	for (std::vector<Item*>::iterator iter = items.begin(); iter != items.end(); ++iter)
	{
		if (*iter == i)
		{
			items.erase(iter);
			break;
		}
	}
}

int Player::hit(int dmg){
	if (!checkAlive()){
		return 0;
	}
	int dmgtodeal;
	if (shield == nullptr){
		dmgtodeal = dmg - defencePower;
	}
	else {
		dmgtodeal = dmg - defencePower - shield->getEquipPower();
	}

	if (dmgtodeal < 0){
		dmgtodeal = 0;
	}
	healthPoints -= (dmgtodeal);
	if (healthPoints <= 0)
		healthPoints = 0;
	return dmgtodeal;
	
}

