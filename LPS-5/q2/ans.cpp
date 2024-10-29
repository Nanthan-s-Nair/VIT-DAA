#include <iostream>
#include <climits>
using namespace std;

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
    int n;
    cin >> n;

    int dims[n];
    for (int i = 0; i < n; i++) {
        cin >> dims[i];
    }

    int result = matrixChainOrder(dims, 1, n - 1);

    cout << result << endl;

    return 0;
}