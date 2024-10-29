#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <fstream>

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

vector<int> generate_random_prices(int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        prices[i] = dis(gen);
    }
    return prices;
}

int main() {
    ofstream outFile("rod_cutting_results.csv");
    outFile << "N,Time (microseconds),Max Revenue" << endl;

    vector<int> sizes = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    for (int n : sizes) {
        vector<int> prices = generate_random_prices(n);

        auto start = chrono::high_resolution_clock::now();
        auto [pieces, revenue] = rod_cutting(prices, n);
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

        outFile << n << "," << duration.count() << "," << revenue << endl;

        cout << "N: " << n << ", Time: " << duration.count() << " microseconds, Max Revenue: " << revenue << endl;
    }

    outFile.close();
    cout << "Results have been written to rod_cutting_results.csv" << endl;

    return 0;
}