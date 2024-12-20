#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    int rows, cols;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    std::vector<std::vector<int>> array(rows, std::vector<int>(cols));

    std::cout << "Enter the elements of the array:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> array[i][j];
        }
    }

    std::vector<int> rowSums(rows, 0);
    std::vector<int> colSums(cols, 0);
    int totalSum = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            rowSums[i] += array[i][j];
            colSums[j] += array[i][j];
            totalSum += array[i][j];
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << std::setw(4) << array[i][j];
        }
        std::cout << "   |" << std::setw(4) << rowSums[i] << std::endl;
    }

    std::cout << "  " << std::string(cols * 4, '-') << "----" << std::endl;
    for (int j = 0; j < cols; ++j) {
        std::cout << std::setw(4) << colSums[j];
    }
    std::cout << "   |" << std::setw(4) << totalSum << std::endl;

    return 0;
}