#include <iostream>

void insertionSort(int* array, int start, int end, bool descending) {
    for (int i = start + 1; i < end; i++) {
        int key = array[i];
        int j = i - 1;

        if (descending) {
            while (j >= start && array[j] < key) {
                array[j + 1] = array[j];
                j--;
            }
        }
        else {
            while (j >= start && array[j] > key) {
                array[j + 1] = array[j];
                j--;
            }
        }
        array[j + 1] = key;
    }
}

void sortHalfArray(int* array, int size) {
    int mid = size / 2;

    insertionSort(array, 0, mid, true);

    insertionSort(array, mid, size, false);
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

    sortHalfArray(array, size);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
