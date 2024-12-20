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

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    std::vector<int> C;
    std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(C));

    C.erase(std::unique(C.begin(), C.end()), C.end());

    std::cout << "Resulting array C (common elements without duplicates):" << std::endl;
    for (int elem : C) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
