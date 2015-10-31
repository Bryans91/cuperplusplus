#pragma once
#include "stdafx.h"
#include "Dungeon.h"

Dungeon::Dungeon(){
	level = 0;
}

Dungeon::~Dungeon(){
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