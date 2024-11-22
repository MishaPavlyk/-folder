#include <iostream>
#include <string>
using namespace std;

int main() {
    string number;
    cout << "Enter a six-digit number: ";
    cin >> number;

    if (number.length() == 6 && (number.begin(), number.end(), ::isdigit)) {
        int sum1 = (number[0] - '0') + (number[1] - '0') + (number[2] - '0');
        int sum2 = (number[3] - '0') + (number[4] - '0') + (number[5] - '0');

        if (sum1 == sum2) {
            cout << "The number is lucky!" << endl;
        }
        else {
            cout << "The number is not lucky." << endl;
        }
    }
    else {
        cout << "Error: The number is not six digits long." << endl;
    }

    return 0;
}
