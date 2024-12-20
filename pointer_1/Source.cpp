#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int m, n;
    std::cin >> m;
    std::vector<int> A(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> A[i];
    }

    std::cin >> n;
    std::vector<int> B(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> B[i];
    }

    std::sort(B.begin(), B.end());

    std::vector<int> C;
    for (int elem : A) {
        if (!std::binary_search(B.begin(), B.end(), elem)) {
            if (std::find(C.begin(), C.end(), elem) == C.end()) {
                C.push_back(elem);
            }
        }
    }

    for (int elem : C) {
        std::cout << elem << " ";
    }

    return 0;
}
