#include <iostream>
#include <string>

std::string replaceDotsWithExclamation(const std::string& input) {
    std::string result = input;
    for (char& c : result) {
        if (c == '.') {
            c = '!';
        }
    }
    return result;
}

int main() {
    std::string str;

    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    std::string modifiedStr = replaceDotsWithExclamation(str);
    std::cout << "Modified string: " << modifiedStr << "\n";

    return 0;
}
