#include <iostream>
#include <algorithm> 

void sortArray(int* array, int size, bool descending = false) {
    if (descending) {

        std::sort(array, array + size, [](int a, int b) { return a > b; });
    }
    else {

        std::sort(array, array + size);
    }
}

int main() {
    const int size = 10;
    int array[size];

    std::cout << "Enter 10 numbers: ";
    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }

    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    sortArray(array, size);
    std::cout << "Sorted array (ascending): ";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    sortArray(array, size, true);
    std::cout << "Sorted array (descending): ";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
