#pragma once
#include "stdafx.h"
#include "Dungeon.h"

Dungeon::Dungeon(){
	level = 0;
}

Dungeon::~Dungeon(){
	for (std::map<int, DungeonLayer*>::iterator itr = Levels.begin(); itr != Levels.end(); itr++)
	{
		delete (itr->second);
	}
	Levels.clear();
}

void Dungeon::setLevel(int level, DungeonLayer* layer){
	Levels[level] = layer;
}

void Dungeon::loadLevel(int _level){
	level = _level;
}



Room* Dungeon::getFirstRoom(){
	if (level != 0){
		return Levels[level]->getStart();
	}
	else {
		return nullptr;
	}
}

Room* Dungeon::getLastRoom(){
	if (level != 0){
		return Levels[level]->getEnd();
	}
	else {
		return nullptr;
	}
}

std::map<Room*, Room*> Dungeon::getConnectedRooms() {
	if (level != 0) {
		return Levels[level]->getConnectedRooms();
	}
	else {
		return std::map<Room*,Room*>();
	}
}

DungeonLayer* Dungeon::getCurrentLayer(){
	return Levels[level];
}