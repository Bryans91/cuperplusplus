#pragma once
#include "stdafx.h"
#include "Room.h"

Room::Room(){

}


std::list<std::string> Room::getPossibleActions() {
	return std::list < std::string > {"Run", "Fight", "Inv", "Map", "Stats"};
}

Room::~Room(){

}