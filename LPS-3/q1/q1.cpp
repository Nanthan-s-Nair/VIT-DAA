#include<iostream>
using namespace std;

struct Result {
    int startIndex;
    int endIndex;
    int minSum;
};

Result findMinSumSubarray(int arr[], int n) {
    int currentMinSum = INT8_MAX;
    int currentSum = 0;
    int start = -1, end = -1;

    for(int i = 0; i < n; i++) {
        currentSum += arr[i];

        if(currentSum < currentMinSum) {
            currentMinSum = currentSum;

            if(start == -1) start = i;
            end = i;
        } else {
            currentSum = 0;
            start = end;
        }
    }

    if(start != -1) start++;
    if(end != -1) end++;

    return {start, end, currentMinSum};
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    Result result = findMinSumSubarray(arr, n);
    cout << result.startIndex << endl << result.endIndex << endl << result.minSum;

    return 0;
}