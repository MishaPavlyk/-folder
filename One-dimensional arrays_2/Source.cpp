#include <iostream>
using namespace std;

int main() {
    const int MONTHS = 12;
    double profit[MONTHS];
    int startMonth, endMonth;

    // Input the profits for each month
    cout << "Enter the profit for each month (12 months): ";
    for (int i = 0; i < MONTHS; i++) {
        cin >> profit[i];
    }

    // Input the range of months to analyze
    cout << "Enter the start and end months (1 to 12): ";
    cin >> startMonth >> endMonth;

    // Adjust the month numbers (1-based to 0-based index)
    startMonth--;
    endMonth--;

    double maxProfit = profit[startMonth];
    double minProfit = profit[startMonth];
    int maxMonth = startMonth, minMonth = startMonth;

    // Find the max and min profit in the specified range
    for (int i = startMonth; i <= endMonth; i++) {
        if (profit[i] > maxProfit) {
            maxProfit = profit[i];
            maxMonth = i;
        }
        if (profit[i] < minProfit) {
            minProfit = profit[i];
            minMonth = i;
        }
    }

    cout << "Max profit is in month " << (maxMonth + 1) << " with profit " << maxProfit << endl;
    cout << "Min profit is in month " << (minMonth + 1) << " with profit " << minProfit << endl;

    return 0;
}
