/*
	Conrad Kubacki 2016
	Brainfuck Interpreter
	condziblog.blogspot.com
	http://forum.pasja-informatyki.pl/user/C%E2%98%BAndzi
*/
#include <vector>
#include <iostream>
#include <fstream>
#include <string>


bool loadFromFile(std::vector<char> & instr);
void jump(size_t & ip, char from, char to, bool dir, std::vector<char> & instructions);


int main()
{
	char dataArray[30000];
	char * dataArrayPointer = dataArray;
	std::vector<char> instructions;

	for (size_t i = 0; i < 30000; ++i)
	{
		dataArray[i] = 0;
	}

	if (!loadFromFile(instructions))
	{
		std::cout << "\n\t@Cannot load file. Exiting.";
		std::cin.get();
		std::cin.get();
		return 1;
	}


	for (size_t i = 0; i < instructions.size(); ++i)
	{
		switch (instructions[i])
		{
		case '>':
			dataArrayPointer++; break;
		case '<':
			dataArrayPointer--; break;
		case '+':
			(*dataArrayPointer)++; break;
		case '-':
			(*dataArrayPointer)--; break;
		case '.':
			std::cout << *dataArrayPointer; break;
		case ',':
			std::cout << "$ ";
			std::cin.get(*dataArrayPointer); break;
		case '[':
			if (!*dataArrayPointer)
			{
				jump(i, '[', ']', true, instructions);
			}
			break;
		case ']':
			if (*dataArrayPointer)
			{
				jump(i, ']', '[', false, instructions);
			}
			break;
		}
	}

	std::cout << "\n\t!Interpretation complete!\n";
	std::cin.get();
	std::cin.get();
	
	return 0;
}


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
