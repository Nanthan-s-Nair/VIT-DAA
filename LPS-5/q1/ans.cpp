#include<iostream>
#include <vector>
using namespace std;

int catalan(int n) {
    vector<int> catalan_numbers(n+1, 0);
    catalan_numbers[0] = 1;  // C(0) = 1
    catalan_numbers[1] = 1;  // C(1) = 1
    // Calculate the Catalan numbers up to C(n)
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            catalan_numbers[i] += catalan_numbers[j] * catalan_numbers[i-j-1];
        }
    }
    return catalan_numbers[n];
}

int main() {
    int n;
    cin >> n;

    if (n < 2) {
        cout << "The number of matrices must be at least 2." << endl;
        return 0;
    }
    cout << catalan(n-1);

    return 0;
}