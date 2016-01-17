#pragma once
#include "stdafx.h"
#include "DungeonLayer.h"



DungeonLayer::DungeonLayer()
{
}


DungeonLayer::~DungeonLayer()
{
	roomList.clear();
	mapLayout.clear();
	start = nullptr;
	end = nullptr;
}

void DungeonLayer::setEnd(Room* r){
	end = r;
}

void DungeonLayer::setStart(Room* r){
	start = r;
}

void DungeonLayer::setMap(std::vector<std::vector<Room*>> map){
	mapLayout = map;
}

void DungeonLayer::setRooms(std::vector<Room*> rms){
	roomList = rms;
}

Room* DungeonLayer::getStart(){
	return start;
}

Room* DungeonLayer::getEnd(){
	return end;
}

std::string DungeonLayer::getDungeonMap(bool c, Room* location){ 
	bool cheat = c;
	std::string returnstring;
	// 2d stringarray voor het 2d te genereren map.
	std::vector<std::vector<char>> mapArray;
	mapArray.resize(mapLayout.size() * 2 - 1);
	for (int i = 0; i < mapArray.size(); i++){
		mapArray[i].resize(mapLayout[0].size() * 2 - 1);
	}

	// prefilling map with . on room and rest space;
	for (int i = 0; i < mapArray.size(); i++){
		for (int j = 0; j < mapArray[i].size(); j++){
			if (i % 2 == 0 && j % 2 == 0){
				mapArray[i][j] = '.';
			}
			else{
				mapArray[i][j] = ' ';
			}
		}
	}
	


	for (int i = 0; i < mapLayout.size(); i++){
		for (int j = 0; j < mapLayout[i].size(); j++){
			if ((cheat || mapLayout[i][j]->isVisited())){
				if (mapLayout[i][j] != start && mapLayout[i][j] != end && mapLayout[i][j] != location){
					mapArray[2 * i][2 * j] = 'N';
				}
				else if (mapLayout[i][j] == location){
					mapArray[2 * i][2 * j] = '@';
				}
				else if (mapLayout[i][j] == start){
					mapArray[2 * i][2 * j] = 'S';
				}
				else if (mapLayout[i][j] == end){
					mapArray[2 * i][2 * j] = 'E';
				}
				else{
					//dunno, just for checking state.
				}
				std::map<Direction, Room*>::iterator it;
				std::map<Direction, Room*> rooms = mapLayout[i][j]->getAdjacentRooms();
				for (it = rooms.begin(); it != rooms.end(); it++)
				{
					switch (it->first)
					{
					case Direction::NORTH:
						mapArray[2 * i - 1][j * 2] = '|';
						break;
					case Direction::EAST:
						mapArray[2 * i][j * 2 + 1] = '-';
						break;
					case Direction::SOUTH:
						mapArray[2 * i + 1][j * 2] = '|';
						break;
					case Direction::WEST:
						mapArray[2 * i][j * 2 - 1] = '-';
						break;
					default:
						break;
					}
				}



			}
		}
		
	}
	returnstring += "Dungeon map:\n";
	for (int i = 0; i < mapArray.size(); i++){
		for (int j = 0; j < mapArray[i].size(); j++){
			returnstring += mapArray[i][j];
		}
		returnstring += "\n";
	}
	returnstring += "\nLegenda:\n-| : Corridors\nS  : Start / Ladder Up\nE  : End Boss / Ladder Down\nN  : Normal Room\n.  : Not Visited\n@  : You\n\n";
	return returnstring;
}


