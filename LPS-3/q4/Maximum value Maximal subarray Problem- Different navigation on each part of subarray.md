## Maximum value Maximal subarray Problem- Different navigation on each part of subarray
In a ‘Maximum subarray Problem’, you are given an array A of integers and the task is to find the contiguous subarray of A such that the sum of the values in the subarray is maximum. In the code for Maximum Subarray Problem (DCC strategy), you will be using a recursive function which takes an array as input. Modify your code in such a way that you navigate from left to right in one part of the array (used by the recursive function) and navigate from right to left in the other part of the array.

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
    Starting Index of the subarray
    Ending Index of the subarray
    The maximum sum of the subarray
    ```
- Example:
    - Input:
        ```
        5
        -10
        2
        5
        12
        -5
        ```
    - Output:
        ```
        2
        4
        19
        ```