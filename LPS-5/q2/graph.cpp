#include <iostream>
#include <climits>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

int matrixChainOrder(int dims[], int i, int j) {
    if (i == j) {
        return 0;
    }

    int min_cost = INT_MAX;

    for (int k = i; k < j; k++) {
        int cost = matrixChainOrder(dims, i, k) +
                   matrixChainOrder(dims, k + 1, j) +
                   dims[i - 1] * dims[k] * dims[j];

        if (cost < min_cost) {
            min_cost = cost;
        }
    }

    return min_cost;
}

int main() {
    ofstream file("matrix_chain_times.csv");
    file << "Size,Time (seconds)\n";

    for (int size = 2; size <= 10; ++size) { // Adjust size range as needed
        int dims[size + 1];
        for (int i = 0; i <= size; ++i) {
            dims[i] = rand() % 100 + 1; // Random dimensions
        }

        auto start = high_resolution_clock::now();
        int result = matrixChainOrder(dims, 1, size);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);

        file << size << "," << duration.count() / 1e9 << "\n";
    }

    file.close();
    cout << "CSV file generated with running times for different sizes." << endl;

    return 0;
}