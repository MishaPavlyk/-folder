#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;


        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
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

    insertionSort(arr);

    std::cout << "Sorted array: \n";
    displayArray(arr);

    return 0;
}