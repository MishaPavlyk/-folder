#include <iostream>
#include <vector>
using namespace std;

void reverseArray() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << "Array in reverse order:\n";
    for (int i = n - 1; i >= 0; --i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    reverseArray();
    return 0;
}
