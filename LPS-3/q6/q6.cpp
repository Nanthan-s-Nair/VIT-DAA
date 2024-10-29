#include <iostream>
#include <climits>
using namespace std;

struct Result {
    int startIdx, endIdx, sum, length;
};

Result calculateCrossSum(int arr[], int low, int mid, int high) {
    int maxLeftSum = INT_MIN;
    int currentLeftSum = 0;
    int leftEndIdx = mid;
    int leftStartIdx = mid;
    int leftLength = 0;
    Result leftResult = {mid, mid, 0, 0};

    for (int i = mid; i >= low; i--) {
        if (arr[i] >= 0) {
            currentLeftSum += arr[i];
            leftEndIdx = i;
            leftLength = leftStartIdx - leftEndIdx + 1;
            if (currentLeftSum > maxLeftSum || (currentLeftSum == maxLeftSum && leftLength > leftResult.length)) {
                maxLeftSum = currentLeftSum;
                leftResult = {leftEndIdx, mid, maxLeftSum, leftLength};
            }
        } else {
            if (i == mid) leftResult = {mid + 1, mid + 1, 0, 0};
            break;
        }
    }

    int maxRightSum = INT_MIN;
    int currentRightSum = 0;
    int rightEndIdx = mid + 1;
    int rightStartIdx = mid + 1;
    int rightLength = 0;
    Result rightResult = {mid + 1, mid + 1, 0, 0};

    for (int i = mid + 1; i <= high; i++) {
        if (arr[i] >= 0) {
            currentRightSum += arr[i];
            rightEndIdx = i;
            rightLength = rightEndIdx - rightStartIdx + 1;
            if (currentRightSum > maxRightSum || (currentRightSum == maxRightSum && rightLength > rightResult.length)) {
                maxRightSum = currentRightSum;
                rightResult = {rightStartIdx, rightEndIdx, maxRightSum, rightLength};
            }
        } else {
            if (i == mid + 1) rightResult = {mid, mid, 0, 0};
            break;
        }
    }

    Result finalResult = {leftResult.startIdx, rightResult.endIdx, rightResult.sum + leftResult.sum, rightResult.length + leftResult.length};
    return finalResult;
}

Result findMaxValidSubarraySum(int arr[], int low, int high) {
    if (arr[low] < 0 && low == high) return {-1, -1, INT_MIN, INT_MAX};
    if (low == high) return {low, low, arr[low], 1};

    int mid = (low + high) / 2;
    Result leftResult = findMaxValidSubarraySum(arr, low, mid);
    Result rightResult = findMaxValidSubarraySum(arr, mid + 1, high);
    Result crossResult = calculateCrossSum(arr, low, mid, high);

    if (crossResult.sum == leftResult.sum && crossResult.sum == rightResult.sum) {
        int maxLength = max(leftResult.length, max(rightResult.length, crossResult.length));
        if (crossResult.length == maxLength) return crossResult;
        if (rightResult.length == maxLength) return rightResult;
        if (leftResult.length == maxLength) return leftResult;
    }
    if (crossResult.sum == leftResult.sum) {
        int maxLength = max(leftResult.length, crossResult.length);
        return (leftResult.length == maxLength) ? leftResult : crossResult;
    }
    if (crossResult.sum == rightResult.sum) {
        int maxLength = max(rightResult.length, crossResult.length);
        return (rightResult.length == maxLength) ? rightResult : crossResult;
    }
    if (crossResult.sum > leftResult.sum && crossResult.sum > rightResult.sum) return crossResult;
    else if (leftResult.sum > crossResult.sum && leftResult.sum > rightResult.sum) return leftResult;
    else return rightResult;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    Result maxSubarrayResult = findMaxValidSubarraySum(arr, 0, n - 1);
    cout << maxSubarrayResult.startIdx + 1 << endl << maxSubarrayResult.endIdx + 1 << endl << maxSubarrayResult.sum;
}