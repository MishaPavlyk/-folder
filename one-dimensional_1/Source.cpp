#include <iostream>
using namespace std;

void calculateProfitForSixMonths() {
    double profit, totalProfit = 0;
    cout << "Enter profit for 6 months:\n";
    for (int i = 1; i <= 6; ++i) {
        cout << "Month " << i << ": ";
        cin >> profit;
        totalProfit += profit;
    }
    cout << "Total profit for 6 months: " << totalProfit << endl;
}

int main() {
    calculateProfitForSixMonths();
    return 0;
}
