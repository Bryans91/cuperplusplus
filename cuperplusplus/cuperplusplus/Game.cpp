#include "stdafx.h"
#include "Game.h"
#include "DungeonGenerator.h"






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
		//ActionFactory::createAction(choice);


	}
}

Game::Game()
{
	Utils::PrintLine("This story is all about you. What was your name again?");
	std::string name = Utils::ReadString();
	player = new Player(name);
	DungeonGenerator* dgen = new DungeonGenerator();
	dungeon = dgen->GenerateDungeon(5, 5);
	delete(dgen);
	Game::startGame();
}

Game::~Game(){

}





