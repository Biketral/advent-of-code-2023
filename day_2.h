#pragma once
#include <iostream>
#include <string>
#include <map>

void execute_day_2();
int extract_game_id(std::string line);
void increase_cubes(std::map<std::string, int> &cubes_count, std::string tmp);
