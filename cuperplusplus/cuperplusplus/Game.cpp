#pragma once
#include "stdafx.h"
#include "Game.h"
#include <algorithm>




Game::Game()
{
	Utils::PrintLine("This story is all about you. What was your name again?");
	name = Utils::ReadString();
	player = new Player(name);
	Utils::LoadPlayer(name, player);
	playing = true;
	Utils::PrintLine("What kind of dungeon do you want? small(4-6), medium(8-10) or large(12-14)? Info: Typo's or nothing will make a medium dungeon");
	size = Utils::ReadString();
	Utils::PrintLine("What difficulty do you want? normal, hard or insane");
	difficulty = Utils::ReadString();
	generateDungeon(size, difficulty);
	dungeon->loadLevel(1);
	player->setCurrentRoom(dungeon->getFirstRoom());
	dungeon->getFirstRoom()->Visited();
	startGame();
}

void Game::generateDungeon(std::string size, std::string difficulty){
	DungeonGenerator* dgen = new DungeonGenerator();
	dungeon = dgen->GenerateDungeon(size, difficulty);
	delete(dgen);
}

void Game::startGame() {
	Utils::cClear();
	while (playing) {
		//fighting loop
		while (fighting){
			if (player->getCurrentRoom()->hasEnemies()){
				Utils::Print("\n" + player->getCurrentRoom()->getEnemyInfo(true));
				Utils::PrintLine(player->getStatus());
				Utils::PrintLine("\nWhat do you want to do?\nAttack | Run | Use Potion | Use Item");
				std::string choice = Utils::ReadString();
				handleInput(choice);
				Utils::cClear();
			}
			else {
				Utils::PrintLine("You defeated the enemy.");
				fighting = false;
			}
			

		}
		// print map
		Utils::Print(dungeon->getCurrentLayer()->getDungeonMap(cheat, player->getCurrentRoom()));
		if (cheat){
			cheat = false;
		}
		if (affected) {
			affected = false;
			Utils::PrintLine(effect);
		}
		if (showStats){
			showStats = false;
			Utils::PrintLine(player->getStatus() + "\n");
		}
		if (showInventory) {
			showInventory = false;
			std::string equipped = "";
			std::string inventory = "";
			

			if (player->getItems().size() == 0 && player->getSword() == nullptr && player->getShield() == nullptr){
				inventory += "You don't have any items right now.";
			}
			else {
				if (player->getSword() != nullptr || player->getShield() != nullptr) {
					equipped += "Equipped:\n";
				}
				inventory += "Inventory: \n";
				for (int i = 0; i < player->getItems().size(); i++){
					if (player->getItems()[i] != player->getSword() && player->getItems()[i] != player->getShield()) {
						inventory += "[" + std::to_string(i + 1) + "] " + std::string(player->getItems()[i]->getText()) + "\n";
					}
					else if (player->getItems()[i] == player->getSword()) {
						equipped += "[" + std::to_string(i + 1) + "]" + player->getSword()->getText() + ": " + std::to_string(player->getSword()->getEquipPower()) + "\n";
					}
					else if (player->getItems()[i] == player->getShield()) {
						equipped += "[" + std::to_string(i + 1) + "]" + player->getShield()->getText() + ": " + std::to_string(player->getShield()->getEquipPower()) + "\n";
					}
				}
				if (player->getSword() != nullptr || player->getShield() != nullptr) {
					equipped += "\n";
				}
			}
			Utils::PrintLine(equipped + inventory + "\n");
		}
		if (compass){
			compass = false;
			std::string compassString = "You take the compass out of your pocket. It lights up and shows you your path: \n\n";
			//TODO shortest path with least amount of enemies.
			compassString += "Output from shortest path stuffs";
			Utils::PrintLine(compassString);
		}
		if (talisman){
			talisman = false;
			std::string talismanString = "You take out the talisman. It whispers to you that the ladder down is ";
			talismanString += std::to_string(player->useTalisman(player->getCurrentRoom(), dungeon->getLastRoom())) + " rooms away"; //TODO bfs for path.
			Utils::PrintLine(talismanString);
		}
		// Print all actions
		if (player->getCurrentRoom() == dungeon->getFirstRoom()) {
			Utils::PrintLine("This is the first room of this layer.");
		} else if (player->getCurrentRoom() == dungeon->getLastRoom()) {
			Utils::PrintLine("You have found the last room in this layer! Do you wish to go down, further into the dungeon?");
		}
		Utils::Print(player->getCurrentRoom()->getRoomInfo());
		player->getCurrentRoom()->checkForTraps(player);
		

		
		actions = "|";
		for (std::string actionString : player->getCurrentRoom()->getPossibleActions()) {
			if (actionString != "") {
				actions += "  " + actionString + "  |";
			}
		}
		if (player->getCurrentRoom() == dungeon->getLastRoom()) {
			actions += "  Down |";
		}
		else if (player->getCurrentRoom() == dungeon->getFirstRoom() && dungeon->getLevel() != 1) {
			actions += "  Up |";
		}
		actions += "  Quit |";
		Utils::PrintLine(actions);
		Utils::PrintLine("Please enter your choice below.");
		std::string choice = Utils::ReadString();
		handleInput(choice);
		Utils::cClear();
		checkHP();
	}

}

void Game::handleInput(std::string input) {
	std::transform(input.begin(), input.end(), input.begin(), ::tolower);
	if (input == std::string("run")) {
		if (fighting) {
			fighting = false;
			Utils::cClear();
		}
		else {
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
	}
	else if (input == std::string("endgame")) {
		endGame();
	}
	else if (input == std::string("cheat")) {
		cheat = true;
	}
	else if (input == std::string("fight")) {
		if (player->getCurrentRoom()->hasEnemies()) {
			fighting = true;
		}
		else {
			Utils::PrintLine("There are no enemies to fight, please select another option");
			handleInput(Utils::ReadString());
		}
	}
	else if (input == std::string("attack")) {
		// currentroom has more enemies

		if (player->getCurrentRoom()->hasEnemies()) {
			if (player->getCurrentRoom()->hasEnemies() > 1 && fighting) {
				Utils::PrintLine("Which monster do you want to attack?");
				int monsterno = std::stoi(Utils::ReadString());

				while (!player->getCurrentRoom()->AttackEnemy(monsterno, player)) {
					Utils::PrintLine("That monster number isn't existing, try again.");
					monsterno = std::stoi(Utils::ReadString());
				}
			}
			else { // only 1;

				player->getCurrentRoom()->AttackEnemy(0, player);
			}
			player->getCurrentRoom()->EnemiesAttack(player);
		}
		else {
			Utils::PrintLine("There are no enemies to attack, please select another option");
			handleInput(Utils::ReadString());
		}
	}
	else if (input == std::string("use")) {
		int item = handleItemInput(Utils::ReadString());
		if (player->hasItems() && item != NULL) {
			Useable* us = dynamic_cast<Useable*>(player->getItems().at(item - 1));
			if (us != NULL) {
				effect = player->useItem(us);
				affect();
			}
		}
		else {
			Utils::PrintLine("You don't seem to have any items to use");
			handleInput(Utils::ReadString());
		}
	}
	else if (input == std::string("equip")) {
		int item = handleItemInput(Utils::ReadString());
		if (player->hasItems()) {
			if (player->getItems().size() >= item) {
				if (player->getItems().at(item - 1) != NULL) {
					Sword* sword = dynamic_cast<Sword*>(player->getItems().at(item - 1));
					Shield* shield = dynamic_cast<Shield*>(player->getItems().at(item - 1));
					if (sword != NULL) {
						sword->equip(player);
					}
					else if (shield != NULL) {
						shield->equip(player);
					}
					else {
						Utils::PrintLine("You can't equip any of these items.");
						handleInput(Utils::ReadString());
					}
				}
				else {
					Utils::PrintLine("You don't seem to have any items to equip.");
					handleInput(Utils::ReadString());
				}
			}
			else {
				Utils::PrintLine("This item doesn't exist.");
				handleInput(Utils::ReadString());
			}
		}
		else {
			Utils::PrintLine("You don't seem to have any items.");
			handleInput(Utils::ReadString());
		}
	}
	else if (input == std::string("unequip")) {
		int item = handleItemInput(Utils::ReadString());
		player->unEquipItem(item);
	}
	else if (input == std::string("inv")){
		showInventory = true;
	}
	else if (input == std::string("stats")){
		showStats = true;
	}
	else if (input == std::string("quit")){
		//save player stats and progress on name, in name.txt
		Utils::PrintLine("Are you sure your wanna quit? Y/N");
		std::string q = Utils::ReadString();
		std::transform(q.begin(), q.end(), q.begin(), ::tolower);
		if (q == "y"){
			playing = false;
		}
	}
	else if(input == std::string("rest")){
		player->heal(5);
		showStats = true;
	}
	else if (input == std::string("item")) {
		if (player->getCurrentRoom()->hasItem()) {
			player->getCurrentRoom()->checkForItems();
		}
		else {
			Utils::PrintLine("There isn't any item in this room, please select another option.");
		}
		handleInput(Utils::ReadString());
	}
	else if (input == std::string("take")) {
		if (player->getCurrentRoom()->hasItem()) {
			player->takeItem(player->getCurrentRoom()->getItem());
			player->getCurrentRoom()->removeItem();
		}
		else {
			Utils::PrintLine("There isn't any item in this room, please select another option.");
			handleInput(Utils::ReadString());
		}
	}
	else if (input == std::string("leave")) {
		
	}
	else if (input == std::string("down")){
		if (player->getCurrentRoom() == dungeon->getLastRoom() && player->getCurrentRoom()->hasEnemies() ==0){
			dungeon->loadNextLevel();
			player->setCurrentRoom(dungeon->getFirstRoom());
			player->getCurrentRoom()->Visited();
		}

	}
	else if (input == std::string("up")){
		if (player->getCurrentRoom() == dungeon->getFirstRoom() && dungeon->getLevel() > 1){
			dungeon->loadLevel(dungeon->getLevel()-1);
			player->setCurrentRoom(dungeon->getLastRoom());
		}

	}
	else if (input == std::string("save")){
		player->save();
	}
	else if (input == std::string("compass")){
		compass = true;
	}
	else if (input == std::string("talisman")){
		talisman = true;
	}
	else if (input == std::string("grenade")) {
		if (grenadeUsed == false) {
			player->useGrenade(player->getCurrentRoom(), dungeon->getLastRoom());
				grenadeUsed = true;
		}
	}
	else {
		Utils::PrintLine("The input " + input + " is not known, try again.");
		handleInput(Utils::ReadString());
	}
}

int Game::handleItemInput(std::string input) {
	if (int i = atoi(input.c_str())) {
		return i;
	}
}

void Game::endGame() {
	playing = false;

}

void Game::affect() {
	affected = true;
	showStats = true;
}

void Game::checkHP() {
	if (player->getHp() <= 0) {
		playing = false;
		player->setHP(player->getMaxHP());
		Utils::LoadPlayer(name, player);
		generateDungeon(size, difficulty);
		dungeon->loadLevel(1);
		player->setCurrentRoom(dungeon->getFirstRoom());
		dungeon->getFirstRoom()->Visited();
		playing = true;
		startGame();
	}
}

Game::~Game()
{
	delete dungeon;
	delete player;
}




