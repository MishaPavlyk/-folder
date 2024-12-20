#include <iostream>
#include <vector>
#include <limits>

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

    int sum = 0;
    int minElement = std::numeric_limits<int>::max();
    int maxElement = std::numeric_limits<int>::min();
    int count = 0;

    for (const auto& row : array) {
        for (int element : row) {
            sum += element;
            if (element < minElement) {
                minElement = element;
            }
            if (element > maxElement) {
                maxElement = element;
            }
            count++;
        }
    }

    double average = static_cast<double>(sum) / count;

    std::cout << "Sum of all elements: " << sum << std::endl;
    std::cout << "Average of all elements: " << average << std::endl;
    std::cout << "Minimum element: " << minElement << std::endl;
    std::cout << "Maximum element: " << maxElement << std::endl;

    return 0;
}
