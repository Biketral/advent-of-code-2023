#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>

int main() {

	std::fstream data {"day_1_data.txt"};
	std::string line {""};

	int sum {0};
	while(std::getline(data, line)) {
		std::cout << line << "\n";
		std::map<int, int> numbers;
		// get number ints
		int counter {0};
		for(char c_char : line) {
			int char_int {static_cast<int>(c_char)};
			if(char_int >= '0' && char_int <= '9') {
				int right_value {c_char - '0'};
				numbers.insert( {counter, right_value });
			}
			counter++;
		}
	/*	
		// get number strings
		const char* digits_str[] = {"one", "two", "three", "four", "five", "six", "seven", "eight",  "nine"};
		for (std::size_t i {0}; i < 9; ++i) {
			std::size_t index = line.find(digits_str[i]);
			if(index >= 0 && (index < numbers.begin()->first || numbers.begin()->first < 0)) {
				numbers.begin()->second = i + 1;
				int tmp {numbers.begin()->second};
				numbers.erase(index);
				numbers.insert({index, tmp});
			}
			index = line.rfind(digits_str[i]);
			if (index >= 0 && (index > numbers.rbegin()->first || numbers.rbegin()->first < 0)) {
                numbers.rbegin()->second = i + 1;
				int tmp {numbers.rbegin()->second};
				numbers.erase(index);
				numbers.insert({index, tmp});
			}*/
      // get number strings
        const char* digits_str[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        for (std::size_t i = 0; i < 9; ++i) {
            std::size_t index = line.find(digits_str[i]);
            if (index != std::string::npos && (index < numbers.begin()->first || numbers.empty())) {
                numbers.begin()->second = i + 1;
            }

            index = line.rfind(digits_str[i]);
            if (index != std::string::npos && (index > numbers.rbegin()->first || numbers.empty())) {
                numbers.rbegin()->second = i + 1;
            }
        }		
		
		

		
		//std::cout << numbers.begin()->second << "  " << numbers.rbegin()->second << "\n";
		//for (auto c : numbers) std::cout << "index: "<< c.first << " , value: " << c.second  << "\n";
		int tmp {0};
		tmp += numbers.begin()->second;
		tmp *= 10;
		tmp += numbers.rbegin()->second;
		sum += tmp;
		numbers.clear();
	}
	std::cout << "the sum is: " << sum << '\n'; 
	data.close();
	return 0;
}
