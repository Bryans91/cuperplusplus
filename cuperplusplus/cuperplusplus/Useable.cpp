#include "stdafx.h"
#include "Useable.h"
#include "Player.h"


Useable::Useable()
{
}

Useable::~Useable()
{
}

std::string Useable::use(Player* p)
{
	return useString;
}
//std::string Useable::save(ItemVisitor v){
//	return v.Visit(this);
//}