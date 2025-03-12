#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

struct FindMin {
    int operator()(const std::vector<int>& vec) const {
        return *std::min_element(vec.begin(), vec.end());
    }
};

struct FindMax {
    int operator()(const std::vector<int>& vec) const {
        return *std::max_element(vec.begin(), vec.end());
    }
};

struct SortDescending {
    void operator()(std::vector<int>& vec) const {
        std::sort(vec.begin(), vec.end(), std::greater<int>());
    }
};

struct SortAscending {
    void operator()(std::vector<int>& vec) const {
        std::sort(vec.begin(), vec.end());
    }
};

struct IncreaseBy {
    int constant;
    IncreaseBy(int c) : constant(c) {}
    void operator()(std::vector<int>& vec) const {
        for (int& num : vec) {
            num += constant;
        }
    }
};

struct DecreaseBy {
    int constant;
    DecreaseBy(int c) : constant(c) {}
    void operator()(std::vector<int>& vec) const {
        for (int& num : vec) {
            num -= constant;
        }
    }
};

struct RemoveValue {
    int value;
    RemoveValue(int v) : value(v) {}
    void operator()(std::vector<int>& vec) const {
        vec.erase(std::remove(vec.begin(), vec.end(), value), vec.end());
    }
};

int main() {
    std::vector<int> numbers = { 5, 2, 9, 1, 5, 6 };

    FindMin findMin;
    std::cout << "Min: " << findMin(numbers) << std::endl;

    FindMax findMax;
    std::cout << "Max: " << findMax(numbers) << std::endl;

    SortDescending sortDesc;
    sortDesc(numbers);
    std::cout << "Sorted Descending: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    SortAscending sortAsc;
    sortAsc(numbers);
    std::cout << "Sorted Ascending: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    IncreaseBy increaseBy5(5);
    increaseBy5(numbers);
    std::cout << "Increased by 5: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    DecreaseBy decreaseBy3(3);
    decreaseBy3(numbers);
    std::cout << "Decreased by 3: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    RemoveValue remove5(5);
    remove5(numbers);
    std::cout << "Removed 5: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}