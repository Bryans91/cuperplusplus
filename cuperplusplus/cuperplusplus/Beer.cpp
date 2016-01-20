#include "stdafx.h"
#include "Beer.h"
#include "Player.h"

static const char * discoveredTrapString = "You feel disappointed as the keg of beer you just find is totally empty.";
static const char * trapString = "You find a keg of beer and drink the entire keg. You feel a bit dizzy and like you feel like you can take on the world. HP+1 AttackPower+3 DefencePower-2.";


Beer::Beer()
{
}


Beer::~Beer()
{
}


void Beer::activate(Player * p)
{
	if (!dismantled) {
		p->heal(1);
		p->increasePwr(3);
		p->increaseDefence(-2);
		dismantled = true;
	}
}

const char * Beer::getText()
{
	if (discoverTrap()) {
		return discoveredTrapString;
	}
	else {
		return trapString;
	}
}