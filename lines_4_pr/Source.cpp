#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string str, original;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    original = str;

    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);

    std::string reversed = str;
    std::reverse(reversed.begin(), reversed.end());

    if (str == reversed) {
        std::cout << "The string \"" << original << "\" is a palindrome." << std::endl;
    }
    else {
        std::cout << "The string \"" << original << "\" is not a palindrome." << std::endl;
    }

    return 0;
}
