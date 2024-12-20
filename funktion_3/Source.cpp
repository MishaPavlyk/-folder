#include <iostream>
#include <limits>

void insertionSort(int* array, int start, int end) {
    for (int i = start + 1; i < end; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= start && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void findAndSortBetweenNegatives(int* array, int size) {
    int left = -1, right = -1;

    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            if (left == -1) {
                left = i;
            }
            right = i;
        }
    }

    if (left != -1 && right != -1 && left < right) {
        insertionSort(array, left + 1, right);
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

    findAndSortBetweenNegatives(array, size);

    std::cout << "Array after sorting between negatives: ";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
