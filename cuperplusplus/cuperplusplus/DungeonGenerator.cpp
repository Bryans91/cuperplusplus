#pragma once
#include "stdafx.h"
#include "DungeonGenerator.h"
#include "stdlib.h"
#include "time.h"
#include <utility>

DungeonGenerator::DungeonGenerator(){
	seeded = false;
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

DungeonLayer* DungeonGenerator::GenerateLayer(int layer){
	DungeonLayer* level = new DungeonLayer();

}



int DungeonGenerator::RandomNumberGenerator(int lowest, int highest){
	if (!seeded){
		srand(time(NULL));
		seeded = true;
	}
	return (lowest + rand() % (highest - lowest + 1));

}