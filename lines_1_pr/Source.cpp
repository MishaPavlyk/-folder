#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    for (char& ch : str) {
        if (ch == ' ') {
            ch = '\t';
        }
    }

    std::cout << "String after replacement: " << str << std::endl;

    return 0;
}
