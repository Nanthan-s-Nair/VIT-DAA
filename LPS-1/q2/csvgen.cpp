#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

// Function to perform insertion sort in ascending order
void insertionSortAsc(vector<int>& vec) {
    int n = vec.size();
    for (int i = 1; i < n; i++) {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && key < vec[j]) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

// Function to perform insertion sort in descending order
void insertionSortDesc(vector<int>& vec) {
    int n = vec.size();
    for (int i = 1; i < n; i++) {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && key > vec[j]) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

// Function to process each file, sort the data, and record timing
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
    vector<int> pos;
    vector<int> neg;
    int value;

    // Read values and separate into positive and negative vectors
    while (inputFile >> value) {
        if (value >= 0) {
            pos.push_back(value);
        } else {
            neg.push_back(value);
        }
    }
    inputFile.close();

    // Start timing
    clock_t start = clock();

    // Sort negative numbers in descending order and positive numbers in ascending order
    insertionSortDesc(neg);
    insertionSortAsc(pos);

    // Merge the two sorted vectors
    neg.insert(neg.end(), pos.begin(), pos.end());

    // Stop timing
    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    // Write sorted output to file
    for (int i = 0; i < n; i++) {
        outputFile << neg[i] << '\n';
    }
    outputFile.close();

    // Write timing results to file
    timingFile << n << ',' << elapsed << '\n';
    timingFile.close();
}

int main() {
    vector<int> sizes;
    sizes.push_back(100);
    sizes.push_back(500);
    sizes.push_back(1000);
    sizes.push_back(2500);
    sizes.push_back(3000);
    sizes.push_back(4500);
    sizes.push_back(5000);
    sizes.push_back(6500);
    sizes.push_back(7500);
    sizes.push_back(10000);

    for (size_t i = 0; i < sizes.size(); ++i) {
        int size = sizes[i];

        // Process random case
        processFile("random_" + to_string(size) + ".txt", "random_sorted_" + to_string(size) + ".txt", "random_results.csv");

        // Process best case
        processFile("best_case_" + to_string(size) + ".txt", "best_case_sorted_" + to_string(size) + ".txt", "best_case_results.csv");

        // Process worst case
        processFile("worst_case_" + to_string(size) + ".txt", "worst_case_sorted_" + to_string(size) + ".txt", "worst_case_results.csv");
    }

    return 0;
}