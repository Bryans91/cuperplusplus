#pragma once
#include "stdafx.h"
#include "DungeonGenerator.h"
#include "stdlib.h"
#include "time.h"
#include "Utils.h"

DungeonGenerator::DungeonGenerator(){
	srand(time(NULL));
}

DungeonGenerator::~DungeonGenerator(){

}

Dungeon* DungeonGenerator::GenerateDungeon(int height, int width){
	Dungeon* d = new Dungeon();
	dungeonHeight = height;
	dungeonWidth = width;
	exitRoom = nullptr;
	int level = 1;
	while (level < 11){
		d->setLevel(level, GenerateLayer(level));
		Utils::PrintLine("Layer " + std::to_string(level) + " created");
		level++;
	}


	return d;

}

DungeonLayer* DungeonGenerator::GenerateLayer(int layer){
	DungeonLayer* dlevel = new DungeonLayer();
	std::vector<std::vector<Room*>> levelArray;
	std::vector<Room*> allRooms;
	std::pair<int, int> startRoom;
	std::pair<int, int> endRoom;
	startRoom.first = RandomNumberGenerator(0, dungeonHeight-1);
	startRoom.second = RandomNumberGenerator(0, dungeonWidth - 1);
	endRoom.first = RandomNumberGenerator(0, dungeonHeight - 1);
	endRoom.second = RandomNumberGenerator(0, dungeonWidth - 1);
	levelArray.resize(dungeonHeight);
	for (int i = 0; i < dungeonHeight; i++){
		levelArray[i].resize(dungeonWidth);
	}
	allRooms.resize(dungeonHeight * dungeonWidth);
	for (int i = 0; i < dungeonHeight; i++){
		int topLinksNeeded = 2;
		int downLinksNeeded = 2;
		for (int j = 0; j < dungeonWidth; j++){
			levelArray[i][j] = new Room();
			allRooms.push_back(levelArray[i][j]);
		}
	}
	for (int i = 0; i < dungeonHeight; i++){
		int downLinksNeeded = 2;

		for (int j = 0; j < dungeonWidth; j++){

			if (j > 0){ // room to left
				levelArray[i][j]->addAdjacentRoom(levelArray[i][j - 1]);
			}
			if (j < dungeonWidth - 1){ // room to the right
				levelArray[i][j]->addAdjacentRoom(levelArray[i][j + 1]);
			}
			if (i < dungeonHeight - 1){ // room to bottom
				if (i + downLinksNeeded == dungeonWidth - 1){// chance of 
					levelArray[i][j]->addAdjacentRoom(levelArray[i + 1][j]);
					levelArray[i + 1][j]->addAdjacentRoom(levelArray[i][j]);
					downLinksNeeded--;
				}
				else{
					if (RandomNumberGenerator(1, 2) == 1){// 1/2 chance of getting room to top
						levelArray[i][j]->addAdjacentRoom(levelArray[i + 1][j]);
						levelArray[i + 1][j]->addAdjacentRoom(levelArray[i][j]);
						downLinksNeeded--;
					}
				}
			}
		}
	}
	dlevel->setEnd(levelArray[endRoom.first][endRoom.second]);
	dlevel->setStart(levelArray[startRoom.first][startRoom.second]);
	dlevel->setRooms(allRooms);

	return dlevel;
}



int DungeonGenerator::RandomNumberGenerator(int lowest, int highest){
	return (lowest + rand() % (highest - lowest + 1));

}