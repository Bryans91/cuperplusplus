#pragma once
#include "stdafx.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include "Player.h"


namespace Utils{

	std::string getCustomPath(){
		return "";
	}

	int Random(){ return Random(0, INT_MAX); }
	int Random(int min){ return Random(0, 10); }
	int Random(int min, int max)
	{
		std::random_device dev;
		std::default_random_engine dre{ dev() };
		std::uniform_int_distribution<int> dist{ min, max };
		int xxx = dist(dre);
		//
		//int xxx = min + std::rand() % (max - min + 1);
		return xxx;
	}

	void Print(std::string text)
	{
		std::cout << text;
	};

	void PrintLine(std::string text)
	{
		std::cout << text << std::endl;
	};

	void PrintCool(std::string text)
	{

		std::chrono::milliseconds timespan(5);
		for (size_t i = 0; i != text.size(); ++i) {
			std::cout << text[i];

			std::this_thread::sleep_for(--timespan);
		}
		std::cout << std::endl;
	};

	std::string ReadString()
	{
		std::string returnz;
		std::cin >> returnz;
		return returnz;
	}

	int ReadLine()
	{
		int inputz;
		std::cin >> inputz;
		while (std::cin.fail()) {
			std::cout << "Incorrect input, probeer nogmaals: " << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> inputz;
		}
		return inputz;
	}


	void SaveFile(std::string text, std::string name){
		if (system("mkdir \"../saves\"")){}
		
		std::string path = "../saves/" + name + ".txt";
		std::ofstream file;
		file.open(path);
		file << text;
		file.close();
		
	}

	void LoadPlayer(std::string name, Player* p){
		std::string path = "../saves/" + name + ".txt";

		std::ifstream file(path);
		if (file.is_open()){
			char const delimiters[] = ": ";
			std::string line;
			std::vector<std::string> lines;
			std::vector<std::string> tokens;
			while (getline(file, line)){
				lines.push_back(line);
			}
			for (int i = 0; i < lines.size(); i++){
				std::string::size_type pos = lines[i].find(': ');
				tokens.push_back(lines[i].substr(0, pos-1));
				tokens.push_back(lines[i].substr(pos + 1, lines[i].size()));
				
			}
			for (int i = 0; i < tokens.size(); i++){
				if (tokens[i] == "Level"){
					p->setLevel(atoi(tokens[i + 1].c_str()));
				}
				else if (tokens[i] == "Hitpoints"){
					p->setHP(atoi(tokens[i + 1].c_str()));
				}
				else if (tokens[i] == "MaxHitpoints"){
					p->setMaxHP(atoi(tokens[i + 1].c_str()));
				}
				else if (tokens[i] == "Attack"){
					p->setPwr(atoi(tokens[i + 1].c_str()));
				}
				else if (tokens[i] == "Defence"){
					p->setDefence(atoi(tokens[i + 1].c_str()));
				}
				else if (tokens[i] == "Experience"){
					p->setExp(atoi(tokens[i + 1].c_str()));
				}
			}
			//handle player stuff;
		}
		else {
			PrintLine("Welcome " + name + ", Good luck in your dungeon.");
		}

	}

	Vector RandomLocation(int width, int height, int floor)
	{
		return Location(Random(0, width - 1), Random(0, height - 1), floor);
	};

	Vector Location(int _x, int _y, int _z)
	{
		Vector p;
		p.x = _x;
		p.y = _y;
		p.z = _z;
		return p;
	}

	void cClear(){ system("cls"); };
	void cPauze(){ system("pause"); };

	bool change(int perc)
	{
		if (perc > 100)
			perc = 100;
		int whut = Random(0, 100);
		return (whut <= perc);//als het random getal gelijk of minder is dat het gekozen perc => true : false
	}

}