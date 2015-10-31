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
	delete start;
	delete end;
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


