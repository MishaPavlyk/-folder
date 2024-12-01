#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    int count = 1000;

    for (int i = 1; i <= count; i++) {
        sum += i;
    }


    double average = static_cast<double>(sum) / count;

    cout << "The average of integers from 1 to 1000 is: " << average << endl;
    return 0;
}
