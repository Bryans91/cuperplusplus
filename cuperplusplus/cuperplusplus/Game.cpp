#pragma once
#include "stdafx.h"
#include "Game.h"
#include "DungeonGenerator.h"




Game::Game()
{
	Utils::PrintLine("This story is all about you. What was your name again?");
	std::string name = Utils::ReadString();
	player = new Player(name);
	DungeonGenerator* dgen = new DungeonGenerator();
	Utils::PrintLine("What size do you want your dungeon? e.g. \"5:4\" will create a dungeon that is 5 wide and 4 high");
	std::string size = Utils::ReadString();
	std::string width = size.substr(0, size.find(":"));
	std::string height = size.substr(1, size.find(":"));
	dungeon = dgen->GenerateDungeon(5, 5);
	delete(dgen);
	
	Game::startGame();
}

void Game::startGame() {
	bool playing = true;

	while (playing) {
		//Utils::cClear();

		// TODO: Draw map with currentroom
		Room* currentRoom = new Room();
		// Print all actions

		actions = "|";
		for (std::string actionString : currentRoom->getPossibleActions()) {
			actions += "  " + actionString + "  |";
		}
		Utils::PrintLine(actions);
		Utils::PrintLine("Please enter your choice below.");
		std::string choice = Utils::ReadString();


	}
}



Game::~Game(){

}




