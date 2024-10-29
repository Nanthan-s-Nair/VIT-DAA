#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

void insertionsort(vector<int>& vec, int& num_comp) {
    int n = vec.size();
    num_comp = 0;
    for (int i = 1; i < n; i++) {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && key < vec[j]) {
            vec[j + 1] = vec[j];
            --j;
            num_comp++;
        }
        vec[j + 1] = key;
        num_comp++;
    }
}

void process_file(const string& filename, const string& output_filename) {
    ifstream input_file(filename);
    if (!input_file) {
        cerr << "Error opening file " << filename << endl;
        return;
    }

    ofstream results(output_filename, ios::app);
    int n, num_comp;
    input_file >> n;
    vector<int> vec(n);

    for (int j = 0; j < n; j++) {
        input_file >> vec[j];
    }
    input_file.close();

    clock_t start = clock();
    insertionsort(vec, num_comp);
    clock_t end = clock();

    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    results << n << "," << elapsed << "\n";
    results.close();
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
        process_file("random_" + to_string(size) + ".txt", "random_results.csv");

        // Process best case
        process_file("best_case_" + to_string(size) + ".txt", "best_case_results.csv");

        // Process worst case
        process_file("worst_case_" + to_string(size) + ".txt", "worst_case_results.csv");
    }

    return 0;
}