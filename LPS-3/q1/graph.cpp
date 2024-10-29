#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

using namespace std;

struct Result {
    int startIndex;
    int endIndex;
    int minSum;
};

Result findMinSumSubarray(const vector<int>& arr) {
    int currentMinSum = numeric_limits<int>::max();
    int currentSum = 0;
    int start = -1, end = -1;
    int n = arr.size();

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
    ofstream outFile("results.csv");
    outFile << "Size,Time (microseconds)" << endl;

    vector<int> sizes = {100, 500, 1000, 5000, 10000,25000, 50000,75000, 100000 };

    for (int size : sizes) {
        vector<int> arr = generateRandomArray(size);

        auto start = chrono::high_resolution_clock::now();
        Result result = findMinSumSubarray(arr);
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

        outFile << size << "," << duration.count() << endl;

        cout << "Size: " << size << ", Time: " << duration.count() << " microseconds" << endl;
    }

    outFile.close();
    cout << "Results have been written to results.csv" << endl;

    return 0;
}