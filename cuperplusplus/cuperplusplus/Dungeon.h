#include <vector>
#include "DungeonLayer.h"
#include "Room.h"
using std::vector;


class Dungeon
{
public:
	Dungeon(int height, int width);
	~Dungeon();
	void setLevel(int level, vector<vector<Room>> layer);

private:
	vector<vector<vector<Room>>> dungeonArray3D;


};
