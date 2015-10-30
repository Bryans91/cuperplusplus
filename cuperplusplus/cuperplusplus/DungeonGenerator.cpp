#pragma once
#include "stdafx.h"
#include "DungeonGenerator.h"
#include "stdlib.h"
#include "time.h"
#include <utility>

DungeonGenerator::DungeonGenerator(){
	srand(time(NULL));
}

DungeonGenerator::~DungeonGenerator(){

}

Dungeon* DungeonGenerator::GenerateDungeon(int height, int width){
	Dungeon* d = new Dungeon(height, width);
	dungeonHeight = height;
	dungeonWidth = width;
	exitRoom = nullptr;
	int level = 1;
	while (level < 11){
		d->setLevel(level, GenerateLayer(level));
	}


	return d;

}

vector<vector<Room>> DungeonGenerator::GenerateLayer(int layer){

}



int RandomNumberGenerator(int lowest, int highest){
	return (rand() % highest + lowest);

}