## Print all LCSs
Rewrite the print LCS routine to print all the LCSs of two sequences

- Input Format
    ```
    First line contains the first string, S1

    Next line contains the second string, S2
    ```

- Output Format
    ```
    Print the length of the longest LCS in the first line

    Print the Longest LCS that we get by traversing from the last cell (m,n) of the b table where m is the length of the first string and n is the length of the second string 
    ```
 

- Example:
    - Input:
        ```
        ABCBDAB
        BDCABA
        ```
    - Output:
        ```
        BCAB
        BCBA
        BDAB
        ```