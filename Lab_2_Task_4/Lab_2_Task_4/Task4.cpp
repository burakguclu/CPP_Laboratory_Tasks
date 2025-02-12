#include <iostream>
#include <vector>

int main() {
	std::vector<std::string> strings;
	std::string input;

	for (int i = 0; i < 5; i++) {
		std::cin >> input;
		strings.push_back(input);
	}

	for (int i = 0; i < strings.size() - 1; i++) {
		for (int j = 0; j < strings.size() - i - 1; j++) {
			if (strings[j] > strings[j + 1]) {
				std::string temp = strings[j];
				strings[j] = strings[j + 1];
				strings[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < strings.size(); i++) {
		strings[i][3] = toupper(strings[i][3]);
	}

	for (int i = 0; i < strings.size(); i++) {
		std::cout << strings[i] << std::endl;
	}

}