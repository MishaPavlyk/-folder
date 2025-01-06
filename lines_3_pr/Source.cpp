#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string sentence;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);

    int wordCount = 0;
    std::istringstream stream(sentence);
    std::string word;

    while (stream >> word) {
        wordCount++;
    }

    std::cout << "Number of words: " << wordCount << std::endl;

    return 0;
}
