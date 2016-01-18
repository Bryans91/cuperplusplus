#pragma once
#include "stdafx.h"
#include "Trap.h"
#include "DungeonGenerator.h"

static const char * trapString = "You don't see any traps in this room.";

Trap::Trap(){
	dismantled = true;
}

const char * Trap::getText() {
	return trapString;
}

void Trap::activate(Player * p)
{
}

bool Trap::discoverTrap()
{
	if (!dismantled) {
		if (DungeonGenerator::RandomNumberGenerator(1, 100) <= discoverChance) {
			dismantled = true;
		}
	}
	return dismantled;
}

Trap::~Trap(){

}