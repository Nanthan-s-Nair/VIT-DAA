## Maximum cost for matrix chain multiplication
Modify the algorithm developed in problem 4 (matrix chain multiplication problem) to find the way to parenthesize that will have maximum number of multiplications. Print the matrices with parenthesis that will have maximum number of multiplications as well. For example given three matrices and dimension as follows:

4
10 100 5 50

The code must print the m table as 
5000 75000 
25000 

S table as
1 1 
2 

Maximum cost is
75000

Paraenthesization of matrices is 
(A1(A2A3))

- Input Format
    ```
    First line contains the number of matrices +1, n
    Next line contains the dimensions of the matrices in the chain
    ```
    
- Output Format
    ```
    Print the mtable

    Print the s table

    Print the maximum cost

    Print the parenthesization that will lead to maximum cost
    ```
 

- Example:

    - Input:
        ```
        4

        10 100 5 50
        ```
    - Output:
        ```
        5000 75000
        25000
        1 1
        2
        75000
        (A1(A2A3))
        ```