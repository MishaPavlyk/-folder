#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

template <typename T>
struct FindMin {
    T operator()(const std::vector<T>& vec) const {
        return *std::min_element(vec.begin(), vec.end());
    }
};

template <typename T>
struct FindMax {
    T operator()(const std::vector<T>& vec) const {
        return *std::max_element(vec.begin(), vec.end());
    }
};

template <typename T>
struct SortDescending {
    void operator()(std::vector<T>& vec) const {
        std::sort(vec.begin(), vec.end(), std::greater<T>());
    }
};

template <typename T>
struct SortAscending {
    void operator()(std::vector<T>& vec) const {
        std::sort(vec.begin(), vec.end());
    }
};

template <typename T>
struct IncreaseBy {
    T constant;
    IncreaseBy(T c) : constant(c) {}
    void operator()(std::vector<T>& vec) const {
        for (T& num : vec) {
            num += constant;
        }
    }
};

template <typename T>
struct DecreaseBy {
    T constant;
    DecreaseBy(T c) : constant(c) {}
    void operator()(std::vector<T>& vec) const {
        for (T& num : vec) {
            num -= constant;
        }
    }
};

template <typename T>
struct RemoveValue {
    T value;
    RemoveValue(T v) : value(v) {}
    void operator()(std::vector<T>& vec) const {
        vec.erase(std::remove(vec.begin(), vec.end(), value), vec.end());
    }
};

int main() {
    std::vector<int> numbers = { 5, 2, 9, 1, 5, 6 };

    FindMin<int> findMin;
    std::cout << "Min: " << findMin(numbers) << std::endl;

    FindMax<int> findMax;
    std::cout << "Max: " << findMax(numbers) << std::endl;

    SortDescending<int> sortDesc;
    sortDesc(numbers);
    std::cout << "Sorted Descending: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    SortAscending<int> sortAsc;
    sortAsc(numbers);
    std::cout << "Sorted Ascending: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    IncreaseBy<int> increaseBy5(5);
    increaseBy5(numbers);
    std::cout << "Increased by 5: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    DecreaseBy<int> decreaseBy3(3);
    decreaseBy3(numbers);
    std::cout << "Decreased by 3: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    RemoveValue<int> remove5(5);
    remove5(numbers);
    std::cout << "Removed 5: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}