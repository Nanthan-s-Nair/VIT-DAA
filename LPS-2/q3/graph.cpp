#include <iostream>
#include <fstream>
#include <chrono>
#include<vector>
using namespace std;

void mergeThree(float array[], int start, int mid1, int mid2, int end) {
    int i = start;
    int j = mid1 + 1;
    int k = mid2 + 1;
    int index = 0;
    float temp[end - start + 1];
    
    while ((i <= mid1) && (j <= mid2) && (k <= end)) {
        if (array[i] <= array[j] && array[i] <= array[k]) {
            temp[index++] = array[i++];
        } else if (array[j] <= array[i] && array[j] <= array[k]) {
            temp[index++] = array[j++];
        } else {
            temp[index++] = array[k++];
        }
    }
    
    while (i <= mid1 && j <= mid2) {
        if (array[i] <= array[j]) {
            temp[index++] = array[i++];
        } else {
            temp[index++] = array[j++];
        }
    }
    
    while (j <= mid2 && k <= end) {
        if (array[j] <= array[k]) {
            temp[index++] = array[j++];
        } else {
            temp[index++] = array[k++];
        }
    }
    
    while (i <= mid1 && k <= end) {
        if (array[i] <= array[k]) {
            temp[index++] = array[i++];
        } else {
            temp[index++] = array[k++];
        }
    }
    
    while (i <= mid1) {
        temp[index++] = array[i++];
    }
    
    while (j <= mid2) {
        temp[index++] = array[j++];
    }
    
    while (k <= end) {
        temp[index++] = array[k++];
    }
    
    for (i = start; i <= end; i++) {
        array[i] = temp[i - start];
    }
}

void mergeSortThree(float array[], int start, int end) {
    if (start < end) {
        int mid1 = start + (end - start) / 3;
        int mid2 = start + 2 * (end - start) / 3;
        mergeSortThree(array, start, mid1);
        mergeSortThree(array, mid1 + 1, mid2);
        mergeSortThree(array, mid2 + 1, end);
        mergeThree(array, start, mid1, mid2, end);
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

    int size;
    inputFile >> size;
    float array[size];
    for (int i = 0; i < size; i++) {
        inputFile >> array[i];
    }
    inputFile.close();

    auto start = chrono::high_resolution_clock::now();
    mergeSortThree(array, 0, size - 1);
    auto end = chrono::high_resolution_clock::now();
    double elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1e9;

    for (int i = 0; i < size; i++) {
        outputFile << array[i] << endl;
    }
    outputFile.close();

    timingFile << size << ',' << elapsed << '\n';
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