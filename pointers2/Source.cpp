#include <iostream>

void reverseArray(int* array, size_t size) {
    int* start = array;
    int* end = array + size - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        ++start;
        --end;
    }
}

int main() {
    size_t size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    if (size == 0) {
        std::cout << "Array size must be greater than zero.\n";
        return 0;
    }

    int* array = new int[size];

    std::cout << "Enter " << size << " elements for the array: ";
    for (size_t i = 0; i < size; ++i) {
        std::cin >> *(array + i);
    }

    reverseArray(array, size);

    std::cout << "Reversed Array: ";
    for (const int* ptr = array; ptr < array + size; ++ptr) {
        std::cout << *ptr << " ";
    }
    std::cout << std::endl;

    delete[] array;

    return 0;
}
