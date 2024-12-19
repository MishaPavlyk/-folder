#include <iostream>

void copyArray(const int* source, int* destination, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        *(destination + i) = *(source + i);
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

    copyArray(sourceArray, destinationArray, size);

    std::cout << "Source Array: ";
    for (const int* ptr = sourceArray; ptr < sourceArray + size; ++ptr) {
        std::cout << *ptr << " ";
    }

    std::cout << "\nDestination Array: ";
    for (const int* ptr = destinationArray; ptr < destinationArray + size; ++ptr) {
        std::cout << *ptr << " ";
    }

    delete[] sourceArray;
    delete[] destinationArray;

    return 0;
}
