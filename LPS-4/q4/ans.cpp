#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int cutRod(int length, const vector<int>& prices, const unordered_set<int>& preferred_lengths, vector<int>& memo) {
    if (length <= 0) return -length;  // penalty for residue
    if (memo[length] != -1) return memo[length];

    int max_revenue = -length;  // init
    for (int cut : preferred_lengths) {
        if (cut <= length) {
            int revenue = prices[cut - 1] + cutRod(length - cut, prices, preferred_lengths, memo);
            max_revenue = max(max_revenue, revenue);
        }
    }

    memo[length] = max_revenue;
    return max_revenue;
}

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int num_preferred;
    cin >> num_preferred;

    unordered_set<int> preferred_lengths;
    for (int i = 0; i < num_preferred; i++) {
        int length;
        cin >> length;
        preferred_lengths.insert(length);
    }

    vector<int> memo(n + 1, -1);
    int max_revenue = cutRod(n, prices, preferred_lengths, memo);

    cout << max_revenue << endl;

    return 0;
}