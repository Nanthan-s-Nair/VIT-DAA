#include <iostream>
#include <map>
#include <vector>
#include <chrono>
#include <random>
#include <fstream>
#include <limits>

using namespace std;

struct Subarray {
    int start_idx, end_idx, sum, length;
};

Subarray findMaxValidSubarraySum(const vector<int>& arr) {
    int max_sum = numeric_limits<int>::min();
    int current_sum = 0;
    int start_idx = -1;
    int end_idx = -1;
    int current_length;
    map<int, Subarray> subarray_map;

    for (int i = 0; i < arr.size(); i++) {
        current_sum += arr[i];

        if (max_sum < current_sum && current_sum > 0) {
            max_sum = current_sum;
            if (start_idx == -1) start_idx = i;
            end_idx = i;
            current_length = end_idx - start_idx + 1;
        } else {
            auto it = subarray_map.begin();
            if (subarray_map.empty() || (it->second).sum <= max_sum) {
                Subarray sub;
                sub.start_idx = start_idx;
                sub.end_idx = end_idx;
                sub.sum = current_sum - arr[i];
                sub.length = current_length;
                if (subarray_map.find(current_sum - arr[i]) == subarray_map.end() || 
                    subarray_map[current_sum - arr[i]].length > sub.length) {
                    if (!subarray_map.empty()) subarray_map.erase(subarray_map.begin());
                    subarray_map[current_sum - arr[i]] = sub;
                }
            }
            current_sum = 0;
            end_idx = -1;
            start_idx = -1;
            current_length = 0;
            max_sum = numeric_limits<int>::min();
        }
    }

    auto it = subarray_map.begin();
    if (subarray_map.empty() || (it->second).sum <= max_sum) {
        Subarray sub;
        sub.start_idx = start_idx;
        sub.end_idx = end_idx;
        sub.sum = max_sum;
        sub.length = current_length;
        if (subarray_map.find(max_sum) == subarray_map.end() || 
            subarray_map[max_sum].length > sub.length) {
            if (!subarray_map.empty()) subarray_map.erase(subarray_map.begin());
            subarray_map[max_sum] = sub;
        }
    }
    return subarray_map.empty() ? Subarray{-1, -1, 0, 0} : (subarray_map.begin())->second;
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
    ofstream outFile("results_maxvalidsubarray.csv");
    outFile << "Size,Time (microseconds)" << endl;

    vector<int> sizes = {100, 500, 1000, 5000, 10000, 25000, 50000, 75000, 100000};

    for (int size : sizes) {
        vector<int> arr = generateRandomArray(size);

        auto start = chrono::high_resolution_clock::now();
        Subarray result = findMaxValidSubarraySum(arr);
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

        outFile << size << "," << duration.count() << endl;

        cout << "Size: " << size << ", Time: " << duration.count() << " microseconds" << endl;
    }

    outFile.close();
    cout << "Results have been written to results_maxvalidsubarray.csv" << endl;

    return 0;
}