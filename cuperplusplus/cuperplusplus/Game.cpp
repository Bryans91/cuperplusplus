#pragma once
#include "stdafx.h"
#include "Game.h"
#include "DungeonGenerator.h"




Game::Game()
{
	Utils::PrintLine("This story is all about you. What was your name again?");
	std::string name = Utils::ReadString();
	player = new Player(name);
	playing = true;
	generateDungeon();
	dungeon->loadLevel(1);
	player->setCurrentRoom(dungeon->getFirstRoom());
	startGame();
}

void Game::generateDungeon(){
	DungeonGenerator* dgen = new DungeonGenerator();
	dungeon = dgen->GenerateDungeon(dgen->RandomNumberGenerator(4,6), dgen->RandomNumberGenerator(4,6));
	delete(dgen);
}

void Game::startGame() {
	while (playing) {
		//Utils::cClear();

		// TODO: Draw map with currentroom
		// Print all actions
		Utils::PrintLine(player->getCurrentRoom()->getRoomInfo());
		actions = "|";
		for (std::string actionString : player->getCurrentRoom()->getPossibleActions()) {
			actions += "  " + actionString + "  |";
		}
		Utils::PrintLine(actions);
		Utils::PrintLine("Please enter your choice below.");
		std::string choice = Utils::ReadString();
		if (choice == std::string("endgame")) {
			endGame();
		}
	}
}

void Game::endGame() {
	playing = false;
}

Game::~Game()
{
}




