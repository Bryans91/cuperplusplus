#pragma once
#include "stdafx.h"
#include "Room.h"
#include "DungeonGenerator.h"
#include "Utils.h"
#define stringify( name ) # name

Room::Room(){
	//Size switch
	switch (DungeonGenerator::RandomNumberGenerator(1, 3)){
	case 1: size = Size::SMALL;
		break;
	case 2: size = Size::MEDIUM;
		break;
	case 3: size = Size::LARGE;
		break;
	default: size = Size::MEDIUM;
		break;
	}
	// State switch
	switch (DungeonGenerator::RandomNumberGenerator(1, 2)){
	case 1: state = State::NEAT;
		break;
	case 2: state = State::DIRTY;
		break;
	default: state = State::NEAT;
		break;
	}
	//Furniture switch
	switch (DungeonGenerator::RandomNumberGenerator(1, 3)){
	case 1: furniture = Furniture::TABLE;
		break;
	case 2: furniture = Furniture::BED;
		break;
	case 3: furniture = Furniture::EMPTY;
		break;
	default: furniture = Furniture::EMPTY;
		break;
	}
	//Lighting switch
	switch (DungeonGenerator::RandomNumberGenerator(1, 3)){
	case 1: lighting = Lighting::CANDLE;
		break;
	case 2: lighting = Lighting::TORCH;
		break;
	case 3: lighting = Lighting::FIRE;
		break;
	default: lighting = Lighting::TORCH;
		break;
	}
	Utils::PrintLine("Room created");
}


std::list<std::string> Room::getPossibleActions() {
	return std::list < std::string > {"Run", "Fight", "Inv", "Map", "Stats"};
}

Room::~Room(){

}