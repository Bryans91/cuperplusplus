#pragma once
#include "stdafx.h"
#include "DungeonGenerator.h"
#include "stdlib.h"
#include "time.h"
#include "Utils.h"
#include "Enemy.h"
#include <algorithm>

DungeonGenerator::DungeonGenerator(){
	srand(time(NULL));
}

DungeonGenerator::~DungeonGenerator(){

}

Dungeon* DungeonGenerator::GenerateDungeon(std::string size, std::string difficulty){
	std::string Size = size;
	std::transform(Size.begin(), Size.end(), Size.begin(), ::tolower);
	std::transform(difficulty.begin(), difficulty.end(), difficulty.begin(), ::tolower);
	if (Size == "small"){
		dungeonHeight = RandomNumberGenerator(4, 6);
		dungeonWidth = RandomNumberGenerator(4, 6);
	}
	else if (Size == "large"){
		dungeonHeight = RandomNumberGenerator(12, 14);
		dungeonWidth = RandomNumberGenerator(12, 14);
	}
	else { // medium size
		dungeonHeight = RandomNumberGenerator(8, 10);
		dungeonWidth = RandomNumberGenerator(8, 10);
	}
	if (difficulty == "hard"){
		difficultylvl = 2;
	}
	else if (difficulty == "insane"){
		difficultylvl = 3;
	}
	Dungeon* d = new Dungeon();

	int level = 1;
	while (level < 11){
		d->setLevel(level, GenerateLayer(level));
		level++;
	}


	return d;
}

DungeonLayer* DungeonGenerator::GenerateLayer(int layer){
	DungeonLayer* dlevel = new DungeonLayer();
	std::vector<std::vector<Room*>> levelArray;
	std::vector<Room*> allRooms;
	std::vector<std::pair<Room*, Room*>> connectedRooms;
	int connections = 0;
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
	for (int i = 0; i < dungeonHeight; i++){
		int topLinksNeeded = 2;
		int downLinksNeeded = 2;
		for (int j = 0; j < dungeonWidth; j++){
			levelArray[i][j] = new Room();
			allRooms.push_back(levelArray[i][j]);
		}
	}
	//link the rooms

	for (int i = 0; i < dungeonHeight; i++){
		int downLinksNeeded = 2;
		int downLinksCreated = 0;

		for (int j = 0; j < dungeonWidth; j++){

			if (j > 0){ // room to left
				levelArray[i][j]->addAdjacentRoom(Direction::WEST, levelArray[i][j - 1]);
				connectedRooms.push_back(std::make_pair(levelArray[i][j], levelArray[i][j - 1]));
			}
			if (j < dungeonWidth - 1){ // room to the right
				levelArray[i][j]->addAdjacentRoom(Direction::EAST, levelArray[i][j + 1]);
			}
			if (i < dungeonHeight - 1){ // room to bottom
				// do i need to create downlink?				
				if (downLinksCreated < downLinksNeeded && j==dungeonWidth-(downLinksNeeded-downLinksCreated)){// room to bottom needed
					levelArray[i][j]->addAdjacentRoom(Direction::SOUTH, levelArray[i + 1][j]);
					levelArray[i + 1][j]->addAdjacentRoom(Direction::NORTH, levelArray[i][j]);
					connectedRooms.push_back(std::make_pair(levelArray[i][j], levelArray[i + 1][j]));
					downLinksCreated++;
				}
				else{
					if (RandomNumberGenerator(1, 2) == 1){// 1/2 chance of getting room to top
						levelArray[i][j]->addAdjacentRoom(Direction::SOUTH, levelArray[i + 1][j]);
						levelArray[i + 1][j]->addAdjacentRoom(Direction::NORTH, levelArray[i][j]);
						connectedRooms.push_back(std::make_pair(levelArray[i][j], levelArray[i + 1][j]));

						downLinksCreated++;
					}
				}
			}			
		}
	}
	//create enemies
	int amountOfEnemies = layer * 5 * difficultylvl;
	for (int i = 0; i < amountOfEnemies; i++){
		Enemy* e = new Enemy(layer);

		std::pair<int, int> eRoom;
		eRoom.first = RandomNumberGenerator(0, dungeonHeight - 1);
		eRoom.second = RandomNumberGenerator(0, dungeonWidth - 1);
		while (eRoom == startRoom){
			eRoom.first = RandomNumberGenerator(0, dungeonHeight - 1);
			eRoom.second = RandomNumberGenerator(0, dungeonWidth - 1);
		}
		levelArray[eRoom.first][eRoom.second]->addEnemy(e);

	}
	if (layer == 5){
		levelArray[endRoom.first][endRoom.second]->addEnemy(new Enemy(layer, true));
	}
	if (layer == 10){//boss creation
		levelArray[endRoom.first][endRoom.second]->addEnemy(new Enemy(layer, true));
	}

	dlevel->setEnd(levelArray[endRoom.first][endRoom.second]);
	dlevel->setStart(levelArray[startRoom.first][startRoom.second]);
	dlevel->setConnectedRooms(connectedRooms);
	dlevel->setRooms(allRooms);
	dlevel->setMap(levelArray);
	levelArray.clear();
	allRooms.clear();
	connectedRooms.clear();
	return dlevel;
}



int DungeonGenerator::RandomNumberGenerator(int lowest, int highest){
	return (lowest + rand() % (highest - lowest + 1));

}