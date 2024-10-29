#include <iostream>
#include <climits>
#include <vector>
#include <chrono>
#include <random>
#include <fstream>

using namespace std;

struct Subarray {
    int start_idx, end_idx, sum, length;
};

Subarray findMaxValidSubarraySum(const vector<int>& arr) {
    int max_sum = INT_MIN;
    int current_sum = 0;
    int start_idx = -1;
    int end_idx = -1;
    int current_length = 0;
    Subarray result = {-1, -1, INT_MIN, 0};

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > 0) {
            current_sum += arr[i];
            if (start_idx == -1) start_idx = i;
            end_idx = i;
            current_length = end_idx - start_idx + 1;

            if (current_sum > max_sum || (current_sum == max_sum && current_length > result.length)) {
                max_sum = current_sum;
                result = {start_idx, end_idx, current_sum, current_length};
            }
        } else if (arr[i] == 0 && current_sum > 0) {
            end_idx = i;
            current_length = end_idx - start_idx + 1;

            if (current_sum > max_sum || (current_sum == max_sum && current_length > result.length)) {
                result = {start_idx, end_idx, current_sum, current_length};
            }
        } else {
            current_sum = 0;
            start_idx = -1;
        }
    }

    if (result.sum == INT_MIN) {
        return {-1, -1, 0, 0};
    }

    return result;
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