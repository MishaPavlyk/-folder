#include <iostream>

int calculateSum(int* arr, int size) {
    int sum = 0;
    int* ptr = arr;
    for (int i = 0; i < size; ++i) {
        sum += *ptr;
        ++ptr;
    }
    return sum;
}

int main() {
    int size;

    std::cout << "Enter the number of elements in the array: ";
    std::cin >> size;

    int* arr = new int[size];

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    int sum = calculateSum(arr, size);
    std::cout << "The sum of the elements is: " << sum << std::endl;

    delete[] arr;
    return 0;
}
