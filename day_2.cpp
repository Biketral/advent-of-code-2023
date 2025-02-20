#include "day_2.h"

#include <iostream>
#include <fstream>
#include <map>
#include <string>

using std::size_t;


int main() {
	execute_day_2();
	return 0; 
}



void execute_day_2() {
	std::fstream data {"day_2_data.txt"};
	std::string line {""};
	int sum {0};
	while(std::getline(data, line)) {
		//std::cout << line << "\n";
		
		// Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
		std::map<std::string, int> cubes_count = { {"blue", 0}, {"red", 0}, {"green", 0} };

		// fill in the map with each colors cubes
		size_t start {(size_t)line.find_first_of(":")};
		std::string tmp {""};
		for (size_t i {start}; i < line.size(); i++) {
			char current_char {line.at(i)};
			if(current_char == ',' || current_char == ';' || i == line.size()-1) {
				if(i == line.size()-1) {
					tmp.push_back(line.back());
				}
				increase_cubes(cubes_count, tmp);
				tmp.clear();
			}
			tmp.push_back(current_char);
		}
		for (const auto &c : cubes_count) {if(cubes_count["red"] == 12)std::cout << c.first << ": " << c.second << "\n";}
		//for (const auto &c : cubes_count) {std::cout << "\t" << c.first << " " << c.second << "\n"; }
			
			
		
			
			
		// check if id should be added to sum
		if(cubes_count["red"] <= 12 && cubes_count["green"] <= 13 && cubes_count["blue"] <= 14) {
			// extract the id from the game 
			std::cout << "lll";
			sum += extract_game_id(line);
		}

		cubes_count.clear();
	}
	std::cout << sum; 
}

int extract_game_id(std::string line) {
	std::string tmp = "";
	for (size_t i {4}; line[i] != ':'; ++i) {
		tmp.push_back(line[i]);
	}
	return std::stoi(tmp);
}

void increase_cubes(std::map<std::string, int> &cubes_count, std::string value) {
	// extract the color string
	int color_pos {(int)value.find_last_of(" ")};
	std::string color {value.substr(++color_pos)};
	 
	// extract the number
	int number_pos {(int)value.find_first_of(" ")};
	color_pos -= 3;
	std::string number_str {value.substr(++number_pos, color_pos)};
	int number {std::stoi(number_str)};

	// increase the cubes for every color
	cubes_count[color] += number;
	//std::cout << color << "  " << number << "\n";
}