#pragma once
#include "stdafx.h"
#include "Room.h"
#include "DungeonGenerator.h"

static const char * sizeStrings[] = { "small", "medium", "large" };
static const char * stateStrings[] = { "neat", "dirty" };
static const char * furnitureStrings[] = { "There is a table with four chairs in this room.", "There is a bed in the corner.", "There is nothing in this room" };
static const char * lightStrings[] = { "In the room there burns a single candle which lights the room a bit.", "On the wall hangs a torch, which lights the room", "On the side there is a big fireplace which fills the room with light." };

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
	
}

const char * Room::getTextForSize(){
	return sizeStrings[size];
}

const char * Room::getTextForState(){
	return stateStrings[state];
}

const char * Room::getTextForFurniture(){
	return furnitureStrings[furniture];
}

const char * Room::getTextForLighting(){
	return  lightStrings[lighting];
}


std::list<std::string> Room::getPossibleActions() {
	return std::list < std::string > {"Run", "Fight", "Inv", "Map", "Stats"};
}

Room::~Room(){

}

std::string Room::getRoomInfo(){
	std::string temp(getTextForSize());
	std::string allInfo = "You enter a " + temp + ", ";
	temp = getTextForState();
	allInfo += temp + " room. ";
	temp = getTextForFurniture();
	allInfo += temp + " ";
	temp = getTextForLighting();
	allInfo += temp;
	return allInfo;
}