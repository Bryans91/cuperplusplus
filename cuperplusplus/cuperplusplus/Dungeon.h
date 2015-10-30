#include <map>
#include "Room.h"
#include "DungeonLayer.h"
using std::map;


class Dungeon
{
public:
	Dungeon(int height, int width);
	~Dungeon();
	void setLevel(int level, DungeonLayer* layer);

private:
	map<int, DungeonLayer> Levels;


};
