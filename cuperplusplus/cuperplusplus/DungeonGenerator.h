#include "Dungeon.h"

class DungeonGenerator
{
public:
	DungeonGenerator();
	~DungeonGenerator();
	Dungeon* GenerateDungeon(int height, int width);
	

private:
	int dungeonWidth, dungeonHeight;
	int RandomNumberGenerator(int lowest, int highest);
	Room GenerateRoom();
	std::pair<int, int>* exitRoom;
	vector<vector<Room>> GenerateLayer(int layer);

};
