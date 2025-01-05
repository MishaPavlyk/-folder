#include <iostream>
#include <vector>
#include <algorithm>

void flip(std::vector<int>& pancakes, int top) {
    std::reverse(pancakes.begin(), pancakes.begin() + top + 1);
}

int pancakeSort(std::vector<int>& pancakes) {
    int flips = 0;
    for (int size = pancakes.size(); size > 1; --size) {
        int maxIndex = std::max_element(pancakes.begin(), pancakes.begin() + size) - pancakes.begin();

        if (maxIndex != size - 1) {
            if (maxIndex != 0) {
                flip(pancakes, maxIndex);
                ++flips;
            }

            flip(pancakes, size - 1);
            ++flips;
        }
    }
    return flips;
}

void displayStack(const std::vector<int>& pancakes) {
    for (int pancake : pancakes) {
        std::cout << pancake << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> pancakes;
    int n;

    std::cout << "Enter the number of pancakes: ";
    std::cin >> n;

    std::cout << "Enter the radii of " << n << " pancakes: ";
    for (int i = 0; i < n; ++i) {
        int radius;
        std::cin >> radius;
        pancakes.push_back(radius);
    }

    std::cout << "Original stack: \n";
    displayStack(pancakes);

    int flips = pancakeSort(pancakes);

    std::cout << "Sorted stack: \n";
    displayStack(pancakes);

    std::cout << "Number of flips: " << flips << std::endl;

    return 0;
}
