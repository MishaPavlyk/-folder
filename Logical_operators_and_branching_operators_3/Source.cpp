#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int numbers[7];
    cout << "Enter 7 integers: ";

    for (int i = 0; i < 7; ++i) {
        cin >> numbers[i];
    }

    int maxNumber = *max_element(numbers, numbers + 7);
    cout << "The maximum number is: " << maxNumber << endl;

    return 0;
}
