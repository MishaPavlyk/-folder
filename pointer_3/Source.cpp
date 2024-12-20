#include <iostream>
#include <vector>

int main() {
    int m;
    std::cout << "Enter the size of array A: ";
    std::cin >> m;

    std::vector<int> A(m);
    std::cout << "Enter elements of array A:" << std::endl;
    for (int i = 0; i < m; ++i) {
        std::cin >> A[i];
    }

    int choice;
    std::cout << "Menu:\n1. Remove even numbers\n2. Remove odd numbers\nEnter your choice: ";
    std::cin >> choice;

    if (choice == 1) {
        A.erase(std::remove_if(A.begin(), A.end(), [](int x) { return x % 2 == 0; }), A.end());
    }
    else if (choice == 2) {
        A.erase(std::remove_if(A.begin(), A.end(), [](int x) { return x % 2 != 0; }), A.end());
    }
    else {
        std::cout << "Invalid choice!" << std::endl;
        return 1;
    }

    std::cout << "Modified array A:" << std::endl;
    for (int elem : A) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
