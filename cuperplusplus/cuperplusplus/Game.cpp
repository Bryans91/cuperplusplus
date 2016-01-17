#pragma once
#include "stdafx.h"
#include "Game.h"
#include <algorithm>




Game::Game()
{
	Utils::PrintLine("This story is all about you. What was your name again?");
	std::string name = Utils::ReadString();
	player = new Player(name);
	playing = true;
	Utils::PrintLine("What kind of dungeon do you want? small(4-6), medium(8-10) or large(12-14)?");
	std::string size = Utils::ReadString();
	generateDungeon(size);
	dungeon->loadLevel(1);
	player->setCurrentRoom(dungeon->getFirstRoom());
	dungeon->getFirstRoom()->Visited();
	startGame();
}

void Game::generateDungeon(std::string size){
	DungeonGenerator* dgen = new DungeonGenerator();
	dungeon = dgen->GenerateDungeon(size);
	delete(dgen);
}

void Game::startGame() {
	Utils::cClear();
	while (playing) {
		

		// TODO: Draw map with currentroom
		Utils::Print(dungeon->getCurrentLayer()->getDungeonMap(cheat, player->getCurrentRoom()));
		if (cheat){
			cheat =  !cheat;
		}
		// Print all actions
		if (player->getCurrentRoom() == dungeon->getFirstRoom()) {
			Utils::PrintLine("This is the first room of this layer.");
		} else if (player->getCurrentRoom() == dungeon->getLastRoom()) {
			Utils::PrintLine("You have found the last room in this layer! Do you wish to go down, further into the dungeon?");
		}
		Utils::PrintLine(player->getCurrentRoom()->getRoomInfo());
		

		
		actions = "|";
		for (std::string actionString : player->getCurrentRoom()->getPossibleActions()) {
			actions += "  " + actionString + "  |";
		}
		Utils::PrintLine(actions);
		Utils::PrintLine("Please enter your choice below.");
		std::string choice = Utils::ReadString();
		handleInput(choice);
		Utils::cClear();


	}
}

void Game::handleInput(std::string input) {
	std::transform(input.begin(), input.end(), input.begin(), ::tolower);
	if (input == std::string("run")) {
		map<Direction, Room*>::iterator it;
		map<Direction, Room*> rooms = player->getCurrentRoom()->getAdjacentRooms();

		Utils::Print("There are exits in the following directions: ");
		for (it = rooms.begin(); it != rooms.end(); it++)
		{
			Utils::Print(it->second->ToString(it->first) + ", ");
		}

		Utils::PrintLine("if you wish to travel type one of these directions below.");
		std::string direction = Utils::ReadString();
		player->goDirection(direction);
	}
	if (input == std::string("endgame")) {
		endGame();
	}
	if (input == std::string("cheat")){
		cheat = true;
	}
}

void Game::endGame() {
	playing = false;

}

Game::~Game()
{
	delete dungeon;
	delete player;
}




