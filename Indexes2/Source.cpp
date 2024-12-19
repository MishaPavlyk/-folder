#include <iostream>

void checkSign(int* num) {
    if (*num > 0) {
        std::cout << "The number is positive." << std::endl;
    }
    else if (*num < 0) {
        std::cout << "The number is negative." << std::endl;
    }
    else {
        std::cout << "The number is zero." << std::endl;
    }
}

int main() {
    int number;

    std::cout << "Enter a number: ";
    std::cin >> number;

    checkSign(&number);

    return 0;
}
