#include <iostream>

void add(int* a, int* b, int* result) {
    *result = *a + *b;
}

void subtract(int* a, int* b, int* result) {
    *result = *a - *b;
}

void multiply(int* a, int* b, int* result) {
    *result = *a * *b;
}

void divide(int* a, int* b, int* result) {
    if (*b != 0) {
        *result = *a / *b;
    }
    else {
        std::cout << "Division by zero is not allowed." << std::endl;
    }
}

int main() {
    int num1, num2, result;
    char operation;

    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter an operator (+, -, *, /): ";
    std::cin >> operation;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    switch (operation) {
    case '+':
        add(&num1, &num2, &result);
        std::cout << "Result: " << result << std::endl;
        break;
    case '-':
        subtract(&num1, &num2, &result);
        std::cout << "Result: " << result << std::endl;
        break;
    case '*':
        multiply(&num1, &num2, &result);
        std::cout << "Result: " << result << std::endl;
        break;
    case '/':
        divide(&num1, &num2, &result);
        if (num2 != 0) {
            std::cout << "Result: " << result << std::endl;
        }
        break;
    default:
        std::cout << "Invalid operator." << std::endl;
    }

    return 0;
}
