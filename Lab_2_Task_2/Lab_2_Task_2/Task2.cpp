#include <iostream>
#include <vector>

int main() {

	float input;
	std::vector<float> numbers;

	for (int i = 0; i < 5; i++) {
		std::cin >> input;
		numbers.push_back(input);
	}

	float smallest = INT64_MAX;
	for (int i = 0; i < numbers.size(); i++) {
		if (smallest > numbers[i])
			smallest = numbers[i];
	}

	std::cout << "Smallest = " << smallest << std::endl;

}