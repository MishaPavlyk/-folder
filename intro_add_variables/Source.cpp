#include <iostream>

int main() {
    double R1, R2, R3, R0;

    std::cout << "Enter the resistance value R1: ";
    std::cin >> R1;
    std::cout << "Enter the resistance value R2: ";
    std::cin >> R2;
    std::cout << "Enter the resistance value R3: ";
    std::cin >> R3;

    if (R1 == 0 || R2 == 0 || R3 == 0) {
        std::cout << "Error: resistance values ​​should not be zero." << std::endl;
        return 1;
    }

    R0 = 1 / ((1 / R1) + (1 / R2) + (1 / R3));

        std::cout << "The value of the equivalent resistance R0: " << R0 << std::endl;

    return 0;
}