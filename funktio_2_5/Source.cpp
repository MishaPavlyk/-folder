#include <iostream>
using namespace std;

int findMax(const int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

int findMax(const int arr[][3], int rows, int cols) {
    int maxVal = arr[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] > maxVal)
                maxVal = arr[i][j];
        }
    }
    return maxVal;
}

int findMax(const int arr[][3][3], int x, int y, int z) {
    int maxVal = arr[0][0][0];
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                if (arr[i][j][k] > maxVal)
                    maxVal = arr[i][j][k];
            }
        }
    }
    return maxVal;
}

int findMax(int a, int b) {
    return (a > b) ? a : b;
}

int findMax(int a, int b, int c) {
    return findMax(findMax(a, b), c);
}

int main() {
    int arr1D[] = { 1, 5, -3, 9, 0, 7 };
    int size1D = sizeof(arr1D) / sizeof(arr1D[0]);
    cout << "Max in 1D array: " << findMax(arr1D, size1D) << endl;

    int arr2D[2][3] = { {3, 8, -1}, {4, 2, 9} };
    cout << "Max in 2D array: " << findMax(arr2D, 2, 3) << endl;

    int arr3D[2][3][3] = {
        {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
        {{-1, -2, -3}, {-4, -5, -6}, {-7, -8, -9}}
    };
    cout << "Max in 3D array: " << findMax(arr3D, 2, 3, 3) << endl;

    int a = 10, b = 20;
    cout << "Max of two integers: " << findMax(a, b) << endl;

    int c = 15;
    cout << "Max of three integers: " << findMax(a, b, c) << endl;

    return 0;
}
