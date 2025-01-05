#include <iostream>
#include <vector>
#include <algorithm>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> arr;
    int n, input;

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> input;
        arr.push_back(input);
    }

    double average = 0;
    for (int num : arr) {
        average += num;
    }
    average /= arr.size();

    int oneThird = arr.size() / 3;
    int twoThirds = 2 * oneThird;

    if (average > 0) {
        quickSort(arr, 0, twoThirds - 1);
    }
    else {
        quickSort(arr, 0, oneThird - 1);
    }

    std::reverse(arr.begin() + twoThirds, arr.end());

    std::cout << "Modified array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
