## Merge-sort algorithm with minimum length subarrays
In the ‘merge-sort’ algorithm, an array of size n, is divided till we get n arrays of size 1. Modify the merge-sort algorithm in such a way that division is not carried out on any subarray of length 4. That is, the minimum length of all the subarrays should be 3 and for the subarray of length 3, apply any constant-time sorting algorithm. Write the code for the modified algorithm.

- Input format:
    ```
    Enter the number of numbers n
    Enter the first number
    Enter the second number
    .....
    Enter the n-th number
    ```

- Output format:
    ```
    Numbers in the increasing order
    ```

- Example:
    - Input:
        ```
        6
        5
        5.5
        6
        3.723
        1.23
        8.88
        ```
    - Output:
        ```
        1.23
        3.723
        5
        5.5
        6
        8.88
        ```