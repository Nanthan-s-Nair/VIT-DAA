#include <iostream>
#include <vector>
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

int main() {
    int n;
    cin >> n;
    vector<float> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    for (const float& num : arr) {
        cout << num << endl;
    }
    return 0;
}