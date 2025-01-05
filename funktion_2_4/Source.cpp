#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

const int SIZE = 100;
const int SEQ_LENGTH = 10;

int findMinSumIndex(int arr[], int start, int minSum, int minIndex) {
    if (start > SIZE - SEQ_LENGTH)
        return minIndex;

    int currentSum = 0;
    for (int i = 0; i < SEQ_LENGTH; i++) {
        currentSum += arr[start + i];
    }

    if (currentSum < minSum) {
        minSum = currentSum;
        minIndex = start;
    }

    return findMinSumIndex(arr, start + 1, minSum, minIndex);
}

int main() {
    srand(time(0));
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100 - 50;
    }

    cout << "Array: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    int minIndex = findMinSumIndex(arr, 0, INT_MAX, 0);

    cout << "The starting position of the sequence with the minimal sum is: " << minIndex << endl;
    cout << "Sequence: ";
    for (int i = 0; i < SEQ_LENGTH; i++) {
        cout << arr[minIndex + i] << " ";
    }
    cout << endl;

    return 0;
}
