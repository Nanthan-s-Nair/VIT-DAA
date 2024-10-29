#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

using namespace std;

struct SubarrayResult {
    int startIndex;
    int endIndex;
    int maxSum;
};

SubarrayResult findCrossSubarray(const vector<int>& arr, int low, int mid, int high) {
    int leftMaxSum = numeric_limits<int>::min();
    int leftIndex = mid;
    int currentSum = 0;

    for(int i = mid; i >= low; i--) {
        currentSum += arr[i];
        if(currentSum > leftMaxSum) {
            leftMaxSum = currentSum;
            leftIndex = i;
        }
    }

    int rightMaxSum = numeric_limits<int>::min();
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

SubarrayResult findMaxSubarray(const vector<int>& arr, int low, int high) {
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
    return {-1, -1, numeric_limits<int>::min()}; // This line should never be reached
}

vector<int> generateRandomArray(int size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(-1000, 1000);

    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }
    return arr;
}

int main() {
    ofstream outFile("results_maxsubarray.csv");
    outFile << "Size,Time (microseconds)" << endl;

    vector<int> sizes = {100, 500, 1000, 5000, 10000,25000, 50000,75000, 100000 };

    for (int size : sizes) {
        vector<int> arr = generateRandomArray(size);

        auto start = chrono::high_resolution_clock::now();
        SubarrayResult result = findMaxSubarray(arr, 0, size - 1);
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

        outFile << size << "," << duration.count() << endl;

        cout << "Size: " << size << ", Time: " << duration.count() << " microseconds" << endl;
    }

    outFile.close();
    cout << "Results have been written to results_maxsubarray.csv" << endl;

    return 0;
}