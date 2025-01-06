#include <iostream>
#include <string>
#include <cctype>

void countCharacters(const std::string& input, int& letterCount, int& digitCount, int& otherCount) {
    letterCount = 0;
    digitCount = 0;
    otherCount = 0;

    for (char c : input) {
        if (std::isalpha(c)) {
            letterCount++;
        }
        else if (std::isdigit(c)) {
            digitCount++;
        }
        else {
            otherCount++;
        }
    }
}

int main() {
    std::string str;
    int letters = 0, digits = 0, others = 0;

    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    countCharacters(str, letters, digits, others);

    std::cout << "Letters: " << letters << "\n";
    std::cout << "Digits: " << digits << "\n";
    std::cout << "Other characters: " << others << "\n";

    return 0;
}
