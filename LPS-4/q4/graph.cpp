#include <iostream>
#include <vector>
#include <unordered_set>
#include <chrono>
#include <fstream>
#include <random>

using namespace std;

int cutRod(int length, const vector<int>& prices, const unordered_set<int>& preferred_lengths, vector<int>& memo) {
    if (length <= 0) return -length;
    if (memo[length] != -1) return memo[length];

    int max_revenue = -length;
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
    ofstream outFile("cut_rod_results.csv");
    outFile << "Length,Time (microseconds),Max Revenue" << endl;

    vector<int> lengths = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> price_dis(1, 100);
    uniform_int_distribution<> length_dis(1, 10);

    for (int n : lengths) {
        vector<int> prices(n);
        for (int i = 0; i < n; i++) {
            prices[i] = price_dis(gen);
        }

        unordered_set<int> preferred_lengths;
        for (int i = 0; i < n / 2; i++) {
            preferred_lengths.insert(length_dis(gen));
        }

        vector<int> memo(n + 1, -1);

        auto start = chrono::high_resolution_clock::now();
        int max_revenue = cutRod(n, prices, preferred_lengths, memo);
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

        outFile << n << "," << duration.count() << "," << max_revenue << endl;

        cout << "Length: " << n << ", Time: " << duration.count() << " microseconds, Max Revenue: " << max_revenue << endl;
    }

    outFile.close();
    cout << "Results have been written to cut_rod_results.csv" << endl;

    return 0;
}