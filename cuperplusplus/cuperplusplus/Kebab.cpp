#include "stdafx.h"
#include "Kebab.h"
#include "Player.h"

static const char * discoveredTrapString = "It looks like as if there was once a kebab here.";
static const char * trapString = "You find a kebab and decide to eat it. It tasted good, but you feel like you need to take a long good s**t after eating it. You feel distracted. HP+5 AttackPower-1 DefencePower-1.";

Kebab::Kebab()
{
}


Kebab::~Kebab()
{
}

void Kebab::activate(Player * p)
{
	if (!dismantled) {
		p->heal(5);
		p->increasePwr(-1);
		p->increaseDefence(-1);
		dismantled = true;
	}
}

const char * Kebab::getText()
{
	if (discoverTrap()) {
		return discoveredTrapString;
	}
	else {
		return trapString;
	}
}