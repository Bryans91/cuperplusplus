#include "stdafx.h"
#include "Game.h"


Game::Game()
{
	Utils::PrintLine("This story is all about you. What was your name again?");
	std::string name = Utils::ReadString();
	player = new Player(name);
	
	startGame();
}

void Game::startGame() {
	bool playing = true;

	while (playing) {
		Utils::cClear();

		// TODO: Draw map with currentroom
		Room* currentRoom = new Room();
		// Print all actions
		actions = ActionFactory::getAllPossibleActions(currentRoom);
		Utils::PrintLine("|   Run   |  Fight  |   Inv   |  Stats  |   Map   |");
		Utils::PrintLine("Please enter your choice below.");
		std::string choice = Utils::ReadString();
		//ActionFactory::createAction(choice);


	}
}



Game::~Game()
{
}
