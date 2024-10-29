#include <iostream>
#include <fstream>
#include <chrono>
#include<vector>
using namespace std;

void merge(float arr[], int l, int m, int r) {
    int i = l;
    int j = m + 1;
    int k = 0;
    float temp[r - l + 1];
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= m) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int p = 0; p < k; p++) {
        arr[l + p] = temp[p];
    }
}

void merges(float arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        merges(arr, l, m);
        merges(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void ins(float arr[], int m, int r) {
    for (int i = m + 1; i <= r; i++) {
        float tmp = arr[i];
        int j = i - 1;
        while (j >= m && arr[j] > tmp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;
    }
}

void processFile(const string& inputFilename, const string& outputFilename, const string& timingFilename) {
    ifstream inputFile(inputFilename);
    if (!inputFile) {
        cerr << "Error opening file " << inputFilename << endl;
        return;
    }

    ofstream outputFile(outputFilename);
    ofstream timingFile(timingFilename, ios::app);

    int n = 0;
    inputFile >> n;
    float arr[n];
    for (int i = 0; i < n; i++) {
        inputFile >> arr[i];
    }
    inputFile.close();

    auto start = chrono::high_resolution_clock::now();
    int l = 0;
    int r = n - 1;
    int m = (l + r) / 2;
    merges(arr, l, m);
    ins(arr, m + 1, r);
    merge(arr, l, m, r);
    auto end = chrono::high_resolution_clock::now();
    double elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1e9;

    for (int i = 0; i < n; i++) {
        outputFile << arr[i] << endl;
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