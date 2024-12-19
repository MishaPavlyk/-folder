#include <iostream>
#include <vector>
#include <cmath>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int* removePrimes(int* arr, int size, int& newSize) {
    std::vector<int> filtered;

    for (int i = 0; i < size; ++i) {
        if (!isPrime(arr[i])) {
            filtered.push_back(arr[i]);
        }
    }

    newSize = filtered.size();

    int* newArr = new int[newSize];

    for (int i = 0; i < newSize; ++i) {
        newArr[i] = filtered[i];
    }

    return newArr;
}

int main() {
    int size;

    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int* arr = new int[size];

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    int newSize;
    int* newArr = removePrimes(arr, size, newSize);

    std::cout << "Array after removing prime numbers: ";
    for (int i = 0; i < newSize; ++i) {
        std::cout << newArr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    delete[] newArr;

    return 0;
}
