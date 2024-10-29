## Recursive Matrix Chain multiplication
Matrix chain multiplication problem aims at finding the optimal way to parenthesize the matrix chain so that the number of multiplications (cost) will be minimum. The matrices are compatible for matrix multiplication so the number of columns in the ith matrix will be equal to number of rows in the (i+1)th matrix. Given dimension of ‘n’ matrices in the chain, write a recursive algorithm and code to find the minimum cost required to multiply the matrices in the chain. For example, if there are three matrices A1, A2, A3 and the dimension are 10 x 100, 100 x 5 and 5 x 50 respectively then input will 10, 100, 5, 50 and minimum cost will be 7500 when parenthesized as ((A1A2)A3).

- Input Format
    ```
    First line contains the number of dimensions (number of matrices in the chain + 1), n
    Next line contain 'n' numbers indicating dimensions of matrices in order
    ```
- Output Format
    ```
    Print the minimum cost (number of multiplications required ) to multiply matrices in the chain.
    ```

- Example:
    - Input:
        ```
        7
        30 35 15 5 10 20 25
        ```
    - Output:
        ```
        15125
        ```