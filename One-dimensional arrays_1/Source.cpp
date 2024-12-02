#include <iostream>
#include <climits>

using namespace std;

int main() {
    const int SIZE = 10;
    int arr[SIZE];

    cout << "Enter " << SIZE << " elements of the array: ";
    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }

    int min = INT_MAX, max = INT_MIN;

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    cout << "Minimum element: " << min << endl;
    cout << "Maximum element: " << max << endl;

    return 0;
}
