#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

int lcs_length(const string &s1, const string &s2) {
    int m = s1.size();
    int n = s2.size();

    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                curr[j] = prev[j - 1] + 1;
            } else {
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        prev = curr;
    }

    return curr[n];
}

int main() {
    ofstream file("lcs_times.csv");
    file << "m,n,LCS Time (microseconds)\n";

    for (int m = 5; m <= 15; m += 2) { // Adjust range as needed
        for (int n = m + 2; n <= m + 5; ++n) { // Ensure n > m
            string s1(m, 'A'); // Random strings of length m
            string s2(n, 'B'); // Random strings of length n

            auto start = high_resolution_clock::now();
            lcs_length(s1, s2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);

            file << m << "," << n << "," << duration.count() << "\n";
        }
    }

    file.close();
    cout << "CSV file generated with LCS computation times." << endl;

    return 0;
}