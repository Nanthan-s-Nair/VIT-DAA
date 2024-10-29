#include <iostream>
#include <climits>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

void matrixChainOrderMax(int dims[], int n) {
    int** m = new int*[n];
    int** s = new int*[n];
    for (int i = 0; i < n; i++) {
        m[i] = new int[n];
        s[i] = new int[n];
    }

    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MIN; 
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (q > m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << m[1][n - 1] << endl;

    for (int i = 0; i < n; i++) {
        delete[] m[i];
        delete[] s[i];
    }
    delete[] m;
    delete[] s;
}

int main() {
    ofstream file("matrix_chain_max_times.csv");
    file << "Size,Time (seconds)\n";

    for (int size = 2; size <= 10; ++size) { // Adjust size range as needed
        int dims[size + 1];
        for (int i = 0; i <= size; ++i) {
            dims[i] = rand() % 100 + 1; // Random dimensions
        }

        auto start = high_resolution_clock::now();
        matrixChainOrderMax(dims, size + 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);

        file << size << "," << duration.count() / 1e9 << "\n";
    }

    file.close();
    cout << "CSV file generated with running times for different sizes." << endl;

    return 0;
}