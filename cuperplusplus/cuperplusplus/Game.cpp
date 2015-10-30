#pragma once
#include "stdafx.h"
#include "Game.h"

Game::Game()
{
	Utils::PrintLine("This story is all about you. What was your name again?");
	std::string name = Utils::ReadString();
	player = new Player(name);
	playing = true;
	Game::startGame();
}

void Game::startGame() {
	while (playing) {
		Utils::cClear();

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
