/*
	Conrad Kubacki 2016
	Brainfuck Interpreter
	condziblog.blogspot.com
	http://forum.pasja-informatyki.pl/user/C%E2%98%BAndzi
*/
#include "Functions.h"

	const uint16_t DATA_ARRAY_SIZE = 30000;

int main()
{
	char dataArray[DATA_ARRAY_SIZE];
	char * dataArrayPointer = dataArray;
	std::vector<char> instructions;

	for (size_t i = 0; i < DATA_ARRAY_SIZE; ++i)
	{
		dataArray[i] = 0;
	}

	if (!loadFromFile(instructions))
	{
		std::cout << "\n\t@Cannot load file. Exiting...";
		std::cin.get();
		std::cin.get();
		return 1;
	}


	for (size_t i = 0; i < instructions.size(); ++i)
	{
		switch (instructions[i])
		{
		case '>':
			dataArrayPointer++; 
			break;

		case '<':
			dataArrayPointer--; 
			break;

		case '+':
			(*dataArrayPointer)++; 
			break;

		case '-':
			(*dataArrayPointer)--; 
			break;

		case '.':
			std::cout << *dataArrayPointer;
			break;

		case ',':
			std::cout << "$ ";
			std::cin.get(*dataArrayPointer); 
			break;

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

	std::cout << "\n\t@Interpretation complete!\n";
	std::cin.get();
	std::cin.get();
	
	return 0;
}


