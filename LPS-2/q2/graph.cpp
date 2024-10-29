#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <string>

using namespace std;

// Constant-time sort for small subarrays (n <= 3)
void insertionSort(vector<double>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        double key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge function to merge two sorted subarrays
void merge(vector<double>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; 
    int n2 = right - mid;   

    vector<double> L(n1);
    vector<double> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Modified Merge Sort function
void mergeSort(vector<double>& arr, int left, int right) {
    if (right - left + 1 <= 3) {
        insertionSort(arr, left, right);
    } else {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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

    int n;
    inputFile >> n;
    vector<double> arr(n);

    for (int i = 0; i < n; i++) {
        inputFile >> arr[i];
    }
    inputFile.close();

    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();
    double elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1e9;

    for (double num : arr) {
        outputFile << num << '\n';
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