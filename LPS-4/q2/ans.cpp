#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<vector<int>, int> rod_cutting(vector<int>& prices, int n) {
    vector<int> max_revenue(n + 1, 0);
    vector<int> cut_sizes(n + 1, 0);

    for (int length = 1; length <= n; length++) {
        for (int i = 1; i <= length; i++) {
            if (i <= prices.size()) {
                if (max_revenue[length] < prices[i - 1] + max_revenue[length - i]) {
                    max_revenue[length] = prices[i - 1] + max_revenue[length - i];
                    cut_sizes[length] = i;
                }
            }
        }
    }

    vector<int> piece_lengths;
    int remaining = n;
    while (remaining > 0) {
        piece_lengths.push_back(cut_sizes[remaining]);
        remaining -= cut_sizes[remaining];
    }

    return {piece_lengths, max_revenue[n]};
}

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    auto [pieces, revenue] = rod_cutting(prices, n);

    for (int piece : pieces) {
        cout << piece << " ";
    }
    cout << revenue << endl;

    return 0;
}