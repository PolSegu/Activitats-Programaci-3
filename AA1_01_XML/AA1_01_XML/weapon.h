#include <string>

struct weapon
{
	int id;
	std::string type;
	int range;

	weapon(int inId, std::string inType, int inRange) : id(inId), type(inType), range(inRange)
	{};
};