#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;

void quickSort(vector<float>& arr, int left, int right) {
    if (left >= right) return;
    float pivot = arr[left + (right - left) / 2];
    int i = left;
    int j = right;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

void processFile(const string& inputFilename, const string& outputFilename, const string& timingFilename) {
    ifstream inputFile(inputFilename);
    if (!inputFile) {
        cerr << "Error opening file " << inputFilename << endl;
        return;
    }

    ofstream outputFile(outputFilename);
    ofstream timingFile(timingFilename, ios::app);

    int n;
    inputFile >> n;
    vector<float> arr(n);
    for (int i = 0; i < n; i++) {
        inputFile >> arr[i];
    }
    inputFile.close();

    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();
    double elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1e9;

    for (const float& num : arr) {
        outputFile << num << endl;
    }
    outputFile.close();

    timingFile << n << ',' << elapsed << '\n';
    timingFile.close();
}

int main() {
    vector<int> sizes = {100, 500, 1000, 2500, 3000, 4500, 5000, 6500, 7500, 10000};

    for (size_t i = 0; i < sizes.size(); ++i) {
        int size = sizes[i];

        // Process best case
        processFile("best_case_" + to_string(size) + ".txt", "best_case_sorted_" + to_string(size) + ".txt", "best_case_results.csv");

        // Process worst case
        processFile("worst_case_" + to_string(size) + ".txt", "worst_case_sorted_" + to_string(size) + ".txt", "worst_case_results.csv");

        // Process average case
        processFile("random_" + to_string(size) + ".txt", "random_sorted_" + to_string(size) + ".txt", "random_results.csv");
    }

    return 0;
}