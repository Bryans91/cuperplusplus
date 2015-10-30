#pragma once
#include "list"
#include "string"
#include "Room.h"

#include "Action.h"
#include "CheckInventory.h"
#include "CheckMap.h"
#include "CheckStats.h"
#include "Fight.h"
#include "Run.h"

class ActionFactory
{
public:
	ActionFactory();
	~ActionFactory();
	static std::list<Action*> getAllPossibleActions(Room*);
	static Action* createAction(std::string);
};

