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

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    std::vector<int> C;

    auto itA = A.begin(), itB = B.begin();
    while (itA != A.end() && itB != B.end()) {
        if (*itA < *itB) {
            if (std::find(C.begin(), C.end(), *itA) == C.end()) {
                C.push_back(*itA);
            }
            ++itA;
        }
        else if (*itA > *itB) {
            if (std::find(C.begin(), C.end(), *itB) == C.end()) {
                C.push_back(*itB);
            }
            ++itB;
        }
        else {
            ++itA;
            ++itB;
        }
    }

    while (itA != A.end()) {
        if (std::find(C.begin(), C.end(), *itA) == C.end()) {
            C.push_back(*itA);
        }
        ++itA;
    }

    while (itB != B.end()) {
        if (std::find(C.begin(), C.end(), *itB) == C.end()) {
            C.push_back(*itB);
        }
        ++itB;
    }

    for (int elem : C) {
        std::cout << elem << " ";
    }

    return 0;
}
