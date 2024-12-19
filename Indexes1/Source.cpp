#include <iostream>

int findMax(int* a, int* b) {
    return (*a > *b) ? *a : *b;
}

int main() {
    int num1, num2;

    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    int max = findMax(&num1, &num2);

    std::cout << "The larger number is: " << max << std::endl;

    return 0;
}
