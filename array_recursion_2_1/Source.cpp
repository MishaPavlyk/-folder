#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void displayArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr;
    int n;

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        arr.push_back(num);
    }

    std::cout << "Original array: \n";
    displayArray(arr);

    bubbleSort(arr);

    std::cout << "Sorted array: \n";
    displayArray(arr);

    return 0;
}
