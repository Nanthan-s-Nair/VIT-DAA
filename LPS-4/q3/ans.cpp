#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxRevenue(int length, int price3, int price5, vector<int>& memo) {
    if (length < 3) return -length;  // pen
    if (length == 3) return price3;
    if (length == 5) return price5;
    if (memo[length] != -1) return memo[length];

    int cut3 = price3 + maxRevenue(length - 3, price3, price5, memo);
    int cut5 = price5 + maxRevenue(length - 5, price3, price5, memo);

    memo[length] = max(cut3, cut5);
    return memo[length];
}

int main() {
    int n;
    cin >> n;

    int price3, price5;
    cin >> price3 >> price5;

    vector<int> memo(n + 1, -1);
    int result = maxRevenue(n, price3, price5, memo);

    cout << result << endl;

    return 0;
}