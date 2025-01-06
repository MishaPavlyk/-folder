#include <iostream>
#include <string>

int countOccurrences(const std::string& input, char target) {
    int count = 0;
    for (char c : input) {
        if (c == target) {
            count++;
        }
    }
    return count;
}

int main() {
    std::string str;
    char target;

    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    std::cout << "Enter the character to count: ";
    std::cin >> target;

    int occurrences = countOccurrences(str, target);
    std::cout << "The character '" << target << "' occurs " << occurrences << " times in the string.\n";

    return 0;
}
