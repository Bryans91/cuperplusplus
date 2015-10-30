class Room
{
public:
	Room();
	~Room();

	enum Size
	{
		SMALL, MEDIUM, LARGE
	};

	enum State
	{
		NEAT, DIRTY
	};

	enum Furnature
	{
		TABLE, BED, EMPTY
	};

	enum Lighting
	{
		CANDLE, TORCH, FIRE
	};

private:
	Size size;
	State state;
	Furnature furnature;
	Lighting lighting;
	std::vector<Room> adjacentRooms;

};
