#include <iostream>
#include <string>

std::string removeAllOccurrences(const std::string& input, char target) {
    std::string result;
    for (char c : input) {
        if (c != target) {
            result += c;
        }
    }
    return result;
}

int main() {
    std::string str;
    char target;

    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    std::cout << "Enter the character to remove: ";
    std::cin >> target;

    std::string result = removeAllOccurrences(str, target);
    std::cout << "Modified string: " << result << "\n";

    return 0;
}
