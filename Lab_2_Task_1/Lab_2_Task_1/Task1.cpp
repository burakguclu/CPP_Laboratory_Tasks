#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> words;

    std::string word1, word2, word3, word4;

    std::cin >> word1;
    words[word1] = word1.length();
    std::cin >> word2;
    words[word2] = word2.length();
    std::cin >> word3;
    words[word3] = word3.length();
    std::cin >> word4;
    words[word4] = word4.length();

    std::cout << word1 << "=" << words[word1] << std::endl;
    std::cout << word2 << "=" << words[word2] << std::endl;
    std::cout << word3 << "=" << words[word3] << std::endl;
    std::cout << word4 << "=" << words[word4] << std::endl;

}
