#include <iostream>
#include <string>

std::string insertCharacter(const std::string& input, char character, size_t position) {
    if (position > input.size()) {
        std::cerr << "Error: Position is out of range.\n";
        return input;
    }
    return input.substr(0, position) + character + input.substr(position);
}

int main() {
    std::string str;
    char character;
    size_t position;

    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    std::cout << "Enter the character to insert: ";
    std::cin >> character;

    std::cout << "Enter the position to insert the character: ";
    std::cin >> position;

    if (position > str.size()) {
        std::cout << "Error: Position is out of range.\n";
    }
    else {
        std::string result = insertCharacter(str, character, position);
        std::cout << "Modified string: " << result << "\n";
    }

    return 0;
}
