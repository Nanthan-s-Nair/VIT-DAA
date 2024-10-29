#include <iostream>
#include <vector>

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
    int n;
    cin >> n;
    
    vector<long long> memo(n+1, -1);
    long long result = myFibonacci(n, memo);
    
    cout << result << endl;
    
    return 0;
}