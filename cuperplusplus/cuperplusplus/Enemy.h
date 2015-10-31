#pragma once
#include "Character.h"

enum Ranks { Ambient, Normal, Veteran, Elite, Champion, Legendary };

class Enemy : public Character
{
private:
	
	Ranks rank{ Ambient };
public:
	Enemy(int lvl);
	Enemy(int lvl, bool isBoss);
	inline std::string ToString(Ranks v)
	{
		switch (v)
		{
		case Ranks::Ambient: return "Ambient";
		case Ranks::Normal:return "Normal";
		case Ranks::Veteran:return "Veteran";
		case Ranks::Elite:return "Elite";
		case Ranks::Champion:return "Champion";
		case Ranks::Legendary:return "Legendary";
		default: return "MissingNo";
		}
	}
	int getRank(){ return rank; };
	~Enemy();
};
