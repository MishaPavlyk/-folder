#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    int letterCount = 0, digitCount = 0, otherCount = 0;

    for (char ch : str) {
        if (std::isalpha(ch)) {
            letterCount++;
        }
        else if (std::isdigit(ch)) {
            digitCount++;
        }
        else {
            otherCount++;
        }
    }

    std::cout << "Letters: " << letterCount << std::endl;
    std::cout << "Digits: " << digitCount << std::endl;
    std::cout << "Other characters: " << otherCount << std::endl;

    return 0;
}
