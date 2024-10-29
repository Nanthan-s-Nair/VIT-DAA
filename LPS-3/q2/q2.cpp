#include <iostream>
#include <climits>
using namespace std;

struct Subarray {
    int start_idx, end_idx, sum, length;
};

Subarray findMaxValidSubarraySum(int arr[], int size) {
    int max_sum = INT_MIN;
    int current_sum = 0;
    int start_idx = -1;
    int end_idx = -1;
    int current_length = 0;
    Subarray result = {-1, -1, INT_MIN, 0}; // Initialize with INT_MIN to handle all negative or zero arrays

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {  // Only consider positive numbers
            current_sum += arr[i];
            if (start_idx == -1) start_idx = i;  // Mark start of subarray
            end_idx = i;
            current_length = end_idx - start_idx + 1;

            if (current_sum > max_sum || (current_sum == max_sum && current_length > result.length)) {
                max_sum = current_sum;
                result = {start_idx, end_idx, current_sum, current_length};
            }
        } else if (arr[i] == 0 && current_sum > 0) {  // Include zeros in valid subarrays
            end_idx = i;
            current_length = end_idx - start_idx + 1;

            if (current_sum > max_sum || (current_sum == max_sum && current_length > result.length)) {
                result = {start_idx, end_idx, current_sum, current_length};
            }
        } else {  // Reset on negative numbers or starting subarray
            current_sum = 0;
            start_idx = -1;
        }
    }

    // Handle case where no positive subarray was found
    if (result.sum == INT_MIN) {
        return {-1, -1, 0, 0}; // Default case: no valid subarray
    }

    return result;
}

int main() {
    int size;
    cin >> size;

    // Edge case: Empty array
    if (size <= 0) {
        cout << -1 << endl << -1 << endl << 0;
        return 0;
    }

    int arr[size];
    for (int i = 0; i < size; i++) cin >> arr[i];

    Subarray result = findMaxValidSubarraySum(arr, size);

    // If no valid subarray found
    if (result.start_idx == -1) {
        cout << -1 << endl << -1 << endl << 0;
    } else {
        cout << result.start_idx + 1 << endl << result.end_idx + 1 << endl << result.sum;
    }

    return 0;
}