#include <iostream>
#include <climits>
#include <vector>
using namespace std;


void printMatrix(int** mat, int n) {
    for (int i = 1; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    for (int j = n; j < n; j++) {
            cout << mat[n-1][j] << " ";
        }
    
}



void printOptimalParens(int** s, int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}


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

    printMatrix(m, n);

    printMatrix(s, n);

    cout << m[1][n - 1] << endl;

    printOptimalParens(s, 1, n - 1);
    cout << endl;

    for (int i = 0; i < n; i++) {
        delete[] m[i];
        delete[] s[i];
    }
    delete[] m;
    delete[] s;
}

int main() {
    int n;
    cin >> n;

    int dims[n];
    for (int i = 0; i < n; i++) {
        cin >> dims[i];
    }

    matrixChainOrderMax(dims, n);

    return 0;
}