#include <iostream>
#include <vector>

int main() {
	int input, factorial = 1;
	std::vector<int> numbers;

	std::cin >> input;

	for (int i = 1; i < input + 1; i++) {
		factorial = factorial * i;
		numbers.push_back(factorial);
	}

	for (int i = 0; i < numbers.size(); i++) {
		std::cout << numbers[i] << " ";
	}

}