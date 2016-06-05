#include "Functions.h"

bool loadFromFile(std::vector<char>& instr)
{
	std::ifstream file;
	char temp;
	std::string path;

	std::cout << "$$ ";
	std::cin >> path;
	file.open(path);

	if (!file.good())
	{
		return false;
	}

	while (file >> temp)
	{
		instr.push_back(temp);
	}

	file.close();

	return true;
}

void jump(size_t & instID, char from, char to, bool dir, std::vector<char>& instructions)
{
	short depth = 0;
	short direction = -1;

	if (dir)
	{
		direction = 1;
	}

	for (; ; instID += direction)
	{
		if (instructions[instID] == from)
		{
			depth++;
		}
		else if (instructions[instID] == to)
		{
			depth--;
		}

		if (instructions[instID] == to && !depth)
		{
			return;
		}
	}
}
