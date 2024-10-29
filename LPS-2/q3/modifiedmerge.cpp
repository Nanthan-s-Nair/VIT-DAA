#include <iostream>
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

int main() {
    int size;
    cin >> size;
    float array[size];
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }
    mergeSortThree(array, 0, size - 1);
    for (int i = 0; i < size; i++) {
        cout << array[i] << endl;
    }
    return 0;
}