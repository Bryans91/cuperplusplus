#pragma once
#include "stdafx.h"
#include "Item.h"
#include "Player.h"
#include "ItemVisitor.h"

Item::Item(){

}

Item::~Item(){

}

void Item::find(Player* p)
{

}

std::string Item::getText()
{
	return itemDescription;
}

//std::string Item::save(ItemVisitor v){
//	return v.Visit(this);
//}