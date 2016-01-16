#pragma once
#include "stdafx.h"
#include "Game.h"




Game::Game()
{
	Utils::PrintLine("This story is all about you. What was your name again?");
	std::string name = Utils::ReadString();
	player = new Player(name);
	playing = true;
	generateDungeon();
	dungeon->loadLevel(1);
	player->setCurrentRoom(dungeon->getFirstRoom());
	dungeon->getFirstRoom()->Visited();
	startGame();
}

void Game::generateDungeon(){
	DungeonGenerator* dgen = new DungeonGenerator();
	dungeon = dgen->GenerateDungeon(dgen->RandomNumberGenerator(4,6), dgen->RandomNumberGenerator(4,6));
	delete(dgen);
}

void Game::startGame() {
	Utils::cClear();
	while (playing) {
		

		// TODO: Draw map with currentroom
		Utils::Print(dungeon->getCurrentLayer()->getDungeonMap(false, player->getCurrentRoom()));
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
		Utils::cClear(); // TODO Find a good place for this one, after handle input it clears the map, here it clears after you typed run, will print the 
		handleInput(choice);


	}
}

void Game::handleInput(std::string input) {

	if (input == std::string("run") || input == std::string("Run")) {
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
		Utils::Print(dungeon->getCurrentLayer()->getDungeonMap(true, player->getCurrentRoom()));
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




