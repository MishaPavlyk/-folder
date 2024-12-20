#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int m, n;
    std::cout << "Enter the size of array A: ";
    std::cin >> m;
    std::cout << "Enter the size of array B: ";
    std::cin >> n;

    std::vector<int> A(m), B(n);
    std::cout << "Enter elements of array A:" << std::endl;
    for (int i = 0; i < m; ++i) {
        std::cin >> A[i];
    }

    std::cout << "Enter elements of array B:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> B[i];
    }

    std::vector<int> C;
    C.reserve(m + n); 
    C.insert(C.end(), A.begin(), A.end());
    C.insert(C.end(), B.begin(), B.end());

    std::sort(C.begin(), C.end());
    C.erase(std::unique(C.begin(), C.end()), C.end());

    std::cout << "Resulting array C:" << std::endl;
    for (int elem : C) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}