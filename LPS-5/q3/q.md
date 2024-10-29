## Matrix Chain Multiplication Top Down
Develop a top down dynamic programming algorithm to find minimum cost for matrix chain multiplication. Print the tables maintained by the algorithm. For example, when there are six matrices and the input given is 

7
30 35 15 5 10 20 25

M table should be printed as 

15750 7875 9375 11875 15125 
2625 4375 7125 10500 
750 2500 5375 
1000 3500 
5000 
S table should be printed as 
1 1 3 3 3 
2 3 3 3 
3 3 3 
4 5 
5 

- Input Format
    ```
    First line contains the number of matrices +1, n
    Next line contains the dimensions of the matrices in the chain
    ```
- Output Format
    ```
    Print the mtable

    Print the s table

    Print the minimum cost

- Example:
    - Input:
        ```
        7
        30 35 15 5 10 20 25
        ```
    - Output:
        ```
        15750 7875 9375 11875 15125
        2625 4375 7125 10500
        750 2500 5375
        1000 3500
        5000
        1 1 3 3 3
        2 3 3 3
        3 3 3
        4 5
        5
        15125
        ```