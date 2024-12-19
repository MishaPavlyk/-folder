#include <iostream>

void copyArrayReverse(const int* source, int* destination, size_t size) {
    const int* srcEnd = source + size - 1;
    for (size_t i = 0; i < size; ++i) {
        *(destination + i) = *(srcEnd - i);
    }
}

int main() {
    size_t size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int* sourceArray = new int[size];
    int* destinationArray = new int[size];

    std::cout << "Enter " << size << " elements for the source array: ";
    for (size_t i = 0; i < size; ++i) {
        std::cin >> *(sourceArray + i);
    }

    copyArrayReverse(sourceArray, destinationArray, size);

    std::cout << "Source Array: ";
    for (const int* ptr = sourceArray; ptr < sourceArray + size; ++ptr) {
        std::cout << *ptr << " ";
    }

    std::cout << "\nReversed Destination Array: ";
    for (const int* ptr = destinationArray; ptr < destinationArray + size; ++ptr) {
        std::cout << *ptr << " ";
    }

    delete[] sourceArray;
    delete[] destinationArray;

    return 0;
}
