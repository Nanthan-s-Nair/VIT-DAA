#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>

using namespace std;

int maxRevenue(int length, int price3, int price5, vector<int>& memo) {
    if (length < 3) return -length;
    if (length == 3) return price3;
    if (length == 5) return price5;
    if (memo[length] != -1) return memo[length];

    int cut3 = price3 + maxRevenue(length - 3, price3, price5, memo);
    int cut5 = price5 + maxRevenue(length - 5, price3, price5, memo);

    memo[length] = max(cut3, cut5);
    return memo[length];
}

int main() {
    ofstream outFile("max_revenue_results.csv");
    outFile << "Length,Time (microseconds),Max Revenue" << endl;

    vector<int> lengths = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int price3 = 5, price5 = 8;

    for (int n : lengths) {
        vector<int> memo(n + 1, -1);

        auto start = chrono::high_resolution_clock::now();
        int result = maxRevenue(n, price3, price5, memo);
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

        outFile << n << "," << duration.count() << "," << result << endl;

        cout << "Length: " << n << ", Time: " << duration.count() << " microseconds, Max Revenue: " << result << endl;
    }

    outFile.close();
    cout << "Results have been written to max_revenue_results.csv" << endl;

    return 0;
}