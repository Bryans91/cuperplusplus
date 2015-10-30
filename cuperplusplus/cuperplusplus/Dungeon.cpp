#pragma once
#include "stdafx.h"
#include "Dungeon.h"

Dungeon::Dungeon(int height, int width){
	
}

Dungeon::~Dungeon(){

}

void Dungeon::setLevel(int level, DungeonLayer* layer){
	Levels[level] = *layer;
}