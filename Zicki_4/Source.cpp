#include <iostream>
using namespace std;

int main() {
    int num, sum = 0;

    cout << "Enter numbers (enter 0 to stop):" << endl;
    while (true) {
        cin >> num;
        if (num == 0) break;
        sum += num;
    }

    cout << "Total sum: " << sum << endl;
    return 0;
}
