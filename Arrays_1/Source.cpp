#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    int rows, cols;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    int startValue;
    std::cout << "Enter the starting number: ";
    std::cin >> startValue;

    std::vector<std::vector<int>> array(rows, std::vector<int>(cols));

    array[0][0] = startValue;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == 0 && j == 0) {
                continue; 
            }
            else if (j == 0) {
                array[i][j] = array[i - 1][cols - 1] * 2; 
            }
            else {
                array[i][j] = array[i][j - 1] * 2;
            }
        }
    }

    std::cout << "Generated Array:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << std::setw(6) << array[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}
