#include <iostream>
#include <string>

std::string removeCharacter(const std::string& input, size_t position) {
    if (position >= input.size()) {
        return input;
    }
    return input.substr(0, position) + input.substr(position + 1);
}

int main() {
    std::string str;
    size_t position;

    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    std::cout << "Enter the position of the character to remove: ";
    std::cin >> position;

    if (position >= str.size()) {
        std::cout << "Error: Position is out of range.\n";
    }
    else {
        std::string result = removeCharacter(str, position);
        std::cout << "Modified string: " << result << "\n";
    }

    return 0;
}
