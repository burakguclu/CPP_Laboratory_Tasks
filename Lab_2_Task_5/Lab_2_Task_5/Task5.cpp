#include <iostream>
#include <string>
#include <map>

int main() {
	std::string input;
	std::getline(std::cin, input);

	std::map<char, int> counts;
	std::map<char, bool> visited;

	for (int i = 0; i < input.length(); i++) {
		char c = std::tolower(input[i]);
		counts[c]++;
	}

	for (int j = 0; j < input.size(); j++) {
		if (input[j] == ' ')
			continue;
		if (!visited[input[j]]) {
			char c = std::tolower(input[j]);
			std::cout << input[j] << "=" << counts[c] << std::endl;
			visited[input[j]] = true;
		}
	}

}