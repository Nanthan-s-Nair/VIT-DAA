#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

int catalan(int n) {
    vector<int> catalan_numbers(n+1, 0);
    catalan_numbers[0] = 1;  // C(0) = 1
    catalan_numbers[1] = 1;  // C(1) = 1
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            catalan_numbers[i] += catalan_numbers[j] * catalan_numbers[i-j-1];
        }
    }
    return catalan_numbers[n];
}

int main() {
    ofstream file("catalan_times.csv");
    file << "Size,Time (seconds)\n";

    for (int size = 2; size <= 20; ++size) {
        auto start = high_resolution_clock::now();
        int result = catalan(size - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        
        file << size << "," << duration.count() / 1e9 << "\n";
    }

    file.close();
    cout << "CSV file generated with running times for different sizes." << endl;

    return 0;
}