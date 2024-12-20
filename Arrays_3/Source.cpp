#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>

void shiftArray(std::vector<std::vector<int>>& array, int shifts, const std::string& direction) {
    int rows = array.size();
    int cols = array[0].size();

    shifts %= (direction == "up" || direction == "down") ? rows : cols;
    if (shifts == 0) return;

    std::vector<std::vector<int>> temp = array;

    if (direction == "left") {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                temp[i][j] = array[i][(j + shifts) % cols];
            }
        }
    }
    else if (direction == "right") {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                temp[i][j] = array[i][(j - shifts + cols) % cols];
            }
        }
    }
    else if (direction == "up") {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                temp[i][j] = array[(i + shifts) % rows][j];
            }
        }
    }
    else if (direction == "down") {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                temp[i][j] = array[(i - shifts + rows) % rows][j];
            }
        }
    }

    array = temp;
}

int main() {
    int rows, cols;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    std::srand(std::time(0));

    std::vector<std::vector<int>> array(rows, std::vector<int>(cols));
    std::cout << "Original Array:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = std::rand() % 50;
            std::cout << std::setw(4) << array[i][j];
        }
        std::cout << std::endl;
    }

    int shifts;
    std::string direction;
    std::cout << "Enter the number of shifts: ";
    std::cin >> shifts;
    std::cout << "Enter the direction (left, right, up, down): ";
    std::cin >> direction;

    shiftArray(array, shifts, direction);

    std::cout << "Shifted Array:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << std::setw(4) << array[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}
