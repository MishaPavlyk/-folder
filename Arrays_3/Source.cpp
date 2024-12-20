#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime> 
#include <iomanip>

int main() {
    const int rows1 = 5, cols1 = 10;
    const int rows2 = 5, cols2 = 5;

    std::srand(std::time(0));

    int array1[rows1][cols1];
    std::cout << "First Array (5x10):" << std::endl;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            array1[i][j] = std::rand() % 51;
            std::cout << std::setw(4) << array1[i][j];
        }
        std::cout << std::endl;
    }

    int array2[rows2][cols2] = { 0 };

    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < cols2; ++j) {
            int index1 = 2 * j;       
            int index2 = index1 + 1; 

            if (index2 < cols1) {
                array2[i][j] = array1[i][index1] + array1[i][index2];
            }
        }
    }

    std::cout << "\nSecond Array (5x5):" << std::endl;
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < cols2; ++j) {
            std::cout << std::setw(4) << array2[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}