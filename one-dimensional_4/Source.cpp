#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findMaxMinProfitMonth() {
    vector<double> profits(12);
    cout << "Enter profit for 12 months:\n";
    for (int i = 0; i < 12; ++i) {
        cout << "Month " << i + 1 << ": ";
        cin >> profits[i];
    }
    auto maxProfit = max_element(profits.begin(), profits.end());
    auto minProfit = min_element(profits.begin(), profits.end());
    cout << "Maximum profit was in month " << (maxProfit - profits.begin() + 1)
        << " (" << *maxProfit << ")\n";
    cout << "Minimum profit was in month " << (minProfit - profits.begin() + 1)
        << " (" << *minProfit << ")\n";
}

int main() {
    findMaxMinProfitMonth();
    return 0;
}
