## Merge-sort partition is based on the position in the array
Merge-sort algorithm (discussed in the class) works by partioning the input array A recursively into two halves. Here, the partition is based on the position in the array. Instead, design a new algorithm A’ where partioning is based on the values in the input array.

- Input format:

Enter the number of numbers n
Enter the first number
Enter the second number
.....
Enter the n-th number

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