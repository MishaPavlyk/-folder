#include <iostream>
#include <vector>

void distributeElements(const int* arr, int size, int*& positives, int& positiveSize, int*& negatives, int& negativeSize, int*& zeros, int& zeroSize) {
    std::vector<int> positiveVec;
    std::vector<int> negativeVec;
    std::vector<int> zeroVec;

    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            positiveVec.push_back(arr[i]);
        }
        else if (arr[i] < 0) {
            negativeVec.push_back(arr[i]);
        }
        else {
            zeroVec.push_back(arr[i]);
        }
    }

    positiveSize = positiveVec.size();
    positives = new int[positiveSize];
    for (int i = 0; i < positiveSize; ++i) {
        positives[i] = positiveVec[i];
    }

    negativeSize = negativeVec.size();
    negatives = new int[negativeSize];
    for (int i = 0; i < negativeSize; ++i) {
        negatives[i] = negativeVec[i];
    }

    zeroSize = zeroVec.size();
    zeros = new int[zeroSize];
    for (int i = 0; i < zeroSize; ++i) {
        zeros[i] = zeroVec[i];
    }
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

    int* positives = nullptr;
    int* negatives = nullptr;
    int* zeros = nullptr;
    int positiveSize = 0, negativeSize = 0, zeroSize = 0;

    distributeElements(arr, size, positives, positiveSize, negatives, negativeSize, zeros, zeroSize);

    std::cout << "Positive elements: ";
    for (int i = 0; i < positiveSize; ++i) {
        std::cout << positives[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Negative elements: ";
    for (int i = 0; i < negativeSize; ++i) {
        std::cout << negatives[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Zero elements: ";
    for (int i = 0; i < zeroSize; ++i) {
        std::cout << zeros[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    delete[] positives;
    delete[] negatives;
    delete[] zeros;

    return 0;
}
