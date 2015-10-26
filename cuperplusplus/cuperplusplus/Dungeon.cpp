#pragma once
#include "stdafx.h"
#include "Dungeon.h"

Dungeon::Dungeon(int height, int width){
	dungeonArray3D.resize(height);
	for (int i = 0; i < height; i++){
		dungeonArray3D[i].resize(width);
		for (int j = 0; j < width; j++){
			dungeonArray3D[i][j].resize(10);
		}
	}
}

Dungeon::~Dungeon(){

}

void Dungeon::setLevel(int level, vector<vector<Room>> layer){
	for (int i = 0; i < layer.size(); i++){
		for (int j = 0; j < layer[i].size(); j++){
			dungeonArray3D[i][j][level] = layer[i][j];
		}
	}
}