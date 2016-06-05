#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

bool loadFromFile(std::vector<char> & instr);
void jump(size_t & ip, char from, char to, bool dir, std::vector<char> & instructions);