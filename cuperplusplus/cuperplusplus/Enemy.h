#pragma once
#include "Character.h"

class Enemy : public Character
{
private:
	enum ranks { Ambient, Normal, Veteran, Elite, Champion, Legendary };
	ranks rank{ Ambient };
public:
	Enemy(int lvl);
	Enemy(int lvl, bool isBoss);
	inline std::string ToString(ranks v)
	{
		switch (v)
		{
		case Enemy::Ambient: return "Ambient";
		case Enemy::Normal:return "Normal";
		case Enemy::Veteran:return "Veteran";
		case Enemy::Elite:return "Elite";
		case Enemy::Champion:return "Champion";
		case Enemy::Legendary:return "Legendary";
		default: return "MissingNo";
		}
	}
	int getRank(){ return rank; };
	~Enemy();
};
