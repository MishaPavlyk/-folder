#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two range boundaries: ";
    cin >> a >> b;

    if (a > b) {
        swap(a, b);
    }

    cout << "All numbers in the range: ";
    for (int i = a; i <= b; i++) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Even numbers in the range: ";
    for (int i = a; i <= b; i++) {
        if (i % 2 == 0) cout << i << " ";
    }
    cout << endl;

    cout << "Odd numbers in the range: ";
    for (int i = a; i <= b; i++) {
        if (i % 2 != 0) cout << i << " ";
    }
    cout << endl;

    cout << "Numbers divisible by 7: ";
    for (int i = a; i <= b; i++) {
        if (i % 7 == 0) cout << i << " ";
    }
    cout << endl;

    return 0;
}
