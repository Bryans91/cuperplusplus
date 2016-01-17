#pragma once
#include "stdafx.h"
#include "Enemy.h"
#include "DungeonGenerator.h"

Enemy::Enemy(int lvl)
{
	lvl = abs(lvl);
	int base = 10;

	std::string Types[7] = { "Duck", "Turtle", "Cow", "Unicorn", "Barbarian", "Spider", "Dragon" };
	int rank = 0;
	int type = DungeonGenerator::RandomNumberGenerator(0, (sizeof(Types) / sizeof(*Types)) - 1);
	switch (lvl) {
		case 0:
		case 1:
			rank = DungeonGenerator::RandomNumberGenerator(0, 1);
			break;
		case 2:
			rank = DungeonGenerator::RandomNumberGenerator(0, 2);
			break;
		case 3:
			rank = DungeonGenerator::RandomNumberGenerator(1, 2);
			break;
		case 4:
			rank = DungeonGenerator::RandomNumberGenerator(1, 3);
			break;
		case 5:
			rank = DungeonGenerator::RandomNumberGenerator(2, 3);
			break;
		case 6:
			rank = DungeonGenerator::RandomNumberGenerator(2, 4);
			break;
		case 7:
			rank = DungeonGenerator::RandomNumberGenerator(3, 4);
			break;
		case 8:
			rank = DungeonGenerator::RandomNumberGenerator(3, 5);
			break;
		case 9:
			rank = DungeonGenerator::RandomNumberGenerator(4, 5);
			break;
		case 10:
			rank = 5;
			base = base + (type * 2);
			break;

	}
	this->rank = static_cast<Ranks>(rank);

	//
	name = ToString(this->rank) + " " + Types[type];
	//
	attackPower = base + rank + type; // 5/15 tot 16/25
	healthPoints = base + (rank * 10); // 11/22 tot 80/100
	defencePower = rank + lvl; // 0 tot 15(max)
	//
	level = 0;
}

Enemy::Enemy(int lvl, bool isBoss)
{
	lvl = abs(lvl);
	if (lvl == 5)
	{
		name = "BOSS: Your ex";
		healthPoints = 100;
	}
	else
	{
		name = "BOSS: Blue-eyes white dragon";
		healthPoints = 200;
	}
	attackPower = 30;
	defencePower = 20;
	level = 0;
}

Enemy::~Enemy()
{

}