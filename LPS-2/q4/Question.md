## Merge-sort for right subarrays and Insertion-sort for right subarrays
Modify the merge-sort algorithm in such a way that the left subarray (got as a result of the first divison) is divided further till we get a subarray of size 1 and the right-subarray (got as a result of the first division) is not subjected to any division. For sorting the right subarray, apply insertion-sort algorithm. Write the modified algorithm A′ to sort the n-given numbers

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