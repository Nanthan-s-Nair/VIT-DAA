#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <iomanip>

using namespace std;

long long myFibonacci(int n, vector<long long>& memo) {
    if (n <= 0) return 0;
    if (memo[n] != -1) return memo[n];
    
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n == 3) return 2;
    
    memo[n] = myFibonacci(n-1, memo) + myFibonacci(n-2, memo) + myFibonacci(n-3, memo);
    return memo[n];
}

int main() {
    ofstream outFile("fibonacci_results.csv");
    outFile << "N,Time (microseconds),Result" << endl;

    vector<int> sizes = {5, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    for (int n : sizes) {
        vector<long long> memo(n+1, -1);

        auto start = chrono::high_resolution_clock::now();
        long long result = myFibonacci(n, memo);
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

        outFile << n << "," << duration.count() << "," << result << endl;

        cout << "N: " << n << ", Time: " << duration.count() << " microseconds, Result: " << result << endl;
    }

    outFile.close();
    cout << "Results have been written to fibonacci_results.csv" << endl;

    return 0;
}