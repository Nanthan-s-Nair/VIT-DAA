#include <iostream>
#include <map>
using namespace std;

struct Subarray {
    int start_idx, end_idx, sum, length;
};

Subarray findMaxValidSubarraySum(int arr[], int size) {
    int max_sum = INT8_MIN;
    int current_sum = 0;
    int start_idx = -1;
    int end_idx = -1;
    int current_length;
    map<int, Subarray> subarray_map;

    for (int i = 0; i < size; i++) {
        current_sum += arr[i];

        if (max_sum < current_sum && current_sum > 0) {
            max_sum = current_sum;
            if (start_idx == -1) start_idx = i;
            end_idx = i;
            current_length = end_idx - start_idx + 1;
        } else {
            auto it = subarray_map.begin();
            if ((it->second).sum <= max_sum) {
                Subarray sub;
                sub.start_idx = start_idx;
                sub.end_idx = end_idx;
                sub.sum = current_sum - arr[i];
                sub.length = current_length;
                if (subarray_map[current_sum - arr[i]].length == 0 || subarray_map[current_sum - arr[i]].length > sub.length) {
                    subarray_map.erase(subarray_map.begin());
                    subarray_map[current_sum - arr[i]] = sub;
                }
            }
            current_sum = 0;
            end_idx = -1;
            start_idx = -1;
            current_length = 0;
            max_sum = INT8_MIN;
        }
    }

    auto it = subarray_map.begin();
    if ((it->second).sum <= max_sum) {
        Subarray sub;
        sub.start_idx = start_idx;
        sub.end_idx = end_idx;
        sub.sum = max_sum;
        sub.length = current_length;
        if (subarray_map[max_sum].length == 0 || subarray_map[max_sum].length > sub.length) {
            subarray_map.erase(subarray_map.begin());
            subarray_map[max_sum] = sub;
        }
    }
    return (subarray_map.begin())->second;
}

int main() {
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++) cin >> arr[i];

    Subarray result = findMaxValidSubarraySum(arr, size);
    cout << result.start_idx + 1 << endl << result.end_idx + 1 << endl << result.sum;

    return 0;
}