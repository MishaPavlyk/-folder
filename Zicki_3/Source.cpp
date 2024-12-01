#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two range boundaries: ";
    cin >> a >> b;

    if (a > b) {
        swap(a, b);
    }

    int sum = 0;
    for (int i = a; i <= b; i++) {
        sum += i;
    }

    cout << "Sum of numbers in the range: " << sum << endl;
    return 0;
}
