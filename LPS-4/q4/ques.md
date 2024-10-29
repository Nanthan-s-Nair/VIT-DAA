## Cut Rods of Preferred Lengths
A rod cutting company sterling corporation will cut rods of specific lengths only. Given a list of lengths by which this company will make rods, a rod of length ‘n’ and list of prices of each piece of rod that shall be cut by the company, write an algorithm and implement it using top down dynamic programming to find maximum revenue that shall be generated. In that case, give a penalty of Rs 1 for each meter of the residue.

- Input Format
    ```
    First line contains the length of the rod, n
    Next line contains price of various lengths of rods from 1 to n
    Next line cotains the number of preferred lengths
    Next line contains the preferred lengths separated by a space
    ```

- Output Format
    ```
    Print the maximum revenue that may be generated 
    ```
 

- Example:

    - Input:
        ```
        20
        1 5 8 9 10 17 17 20 24 30 31 32 33 34 35 36 37 38 39 40
        2
        3 5
        ```
    - Output:
        ```
        50
        ```