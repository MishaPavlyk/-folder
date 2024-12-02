#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cout << "Enter the size of the array (N): ";
    cin >> N;

    vector<double> arr(N);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int firstNegative = -1, lastNegative = -1;
    for (int i = 0; i < N; i++) {
        if (arr[i] < 0) {
            if (firstNegative == -1) firstNegative = i;
            lastNegative = i;
        }
    }

    double sumBetweenNegatives = 0;
    if (firstNegative != -1 && lastNegative != -1 && firstNegative != lastNegative) {
        for (int i = firstNegative + 1; i < lastNegative; i++) {
            sumBetweenNegatives += arr[i];
        }
    }

    cout << "Sum of elements between the first and last negative elements: " << sumBetweenNegatives << endl;

    return 0;
}
