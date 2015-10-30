#include "stdafx.h"
#include "ActionFactory.h"


ActionFactory::ActionFactory()
{
}

std::list<Action*> ActionFactory::getAllPossibleActions(Room* r) {
	std::list<Action *> actionList;
	for (std::string s : r->getPossibleActions()) {
		actionList.push_back(createAction(s));
	}
	return actionList;
}

Action* ActionFactory::createAction(std::string s) {
	return new Action();
}


ActionFactory::~ActionFactory()
{
}
