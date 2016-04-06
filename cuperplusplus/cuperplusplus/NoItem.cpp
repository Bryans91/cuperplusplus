#include "stdafx.h"
#include "NoItem.h"


NoItem::NoItem()
{
}


NoItem::~NoItem()
{
}

std::string NoItem::save(ItemVisitor iv){
	return "NOITEM\n";
}