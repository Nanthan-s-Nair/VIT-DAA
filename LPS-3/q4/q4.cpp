#include<iostream>
using namespace std;

struct SubarrayResult {
    int startIndex;
    int endIndex;
    int maxSum;
};

SubarrayResult findCrossSubarray(int arr[], int low, int mid, int high) {
    int leftMaxSum = INT8_MIN;
    int leftIndex = mid;
    int currentSum = 0;

    for(int i = mid; i >= low; i--) {
        currentSum += arr[i];
        if(currentSum > leftMaxSum) {
            leftMaxSum = currentSum;
            leftIndex = i;
        }
    }

    int rightMaxSum = INT8_MIN;
    int rightIndex = mid + 1;
    currentSum = 0;

    for(int i = mid + 1; i <= high; i++) {
        currentSum += arr[i];
        if(currentSum > rightMaxSum) {
            rightMaxSum = currentSum;
            rightIndex = i;
        }
    }

    int totalMaxSum = leftMaxSum + rightMaxSum;
    if(totalMaxSum > leftMaxSum && totalMaxSum > rightMaxSum) {
        return {leftIndex, rightIndex, totalMaxSum};
    } else if(rightMaxSum > leftMaxSum) {
        return {mid + 1, rightIndex, rightMaxSum};
    } else {
        return {leftIndex, mid, leftMaxSum};
    }
}

SubarrayResult findMaxSubarray(int arr[], int low, int high) {
    if(low == high) return {low, low, arr[low]};

    if(low < high) {
        int mid = (low + high) / 2;

        SubarrayResult leftSubarray = findMaxSubarray(arr, low, mid);
        SubarrayResult rightSubarray = findMaxSubarray(arr, mid + 1, high);
        SubarrayResult crossSubarray = findCrossSubarray(arr, low, mid, high);

        if(crossSubarray.maxSum > leftSubarray.maxSum && crossSubarray.maxSum > rightSubarray.maxSum) {
            return crossSubarray;
        } else if(leftSubarray.maxSum > crossSubarray.maxSum) {
            return leftSubarray;
        } else {
            return rightSubarray;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    SubarrayResult result = findMaxSubarray(arr, 0, n - 1);
    cout << result.startIndex + 1 << endl << result.endIndex + 1 << endl << result.maxSum;

    return 0;
}