#include "stdafx.h"
#include "Tripwire.h"


static const char * discoveredTrapString = "You find a tripwire that leads into the wall, in the wall there are holes cut out. You carefully step over the tripwire so that you don't activate it.";
static const char * trapString = "You trip over a tripwire and with your quick reflexes you manage to dodge the spikes that appear from the holes in the wall to your left. The bad thing is that there were also spikes coming from the right. Hp -10.";

Tripwire::Tripwire()
{
	dismantled = false;
	discoverChance = 80;
}


Tripwire::~Tripwire()
{
}

const char * Tripwire::getText()
{
	if (discoverTrap()) {
		return discoveredTrapString;
	}
	else {
		dismantled = true;
		return trapString;
	}
}
