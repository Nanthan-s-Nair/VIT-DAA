## Insertion Sort- sorting the points based on the distance from the leftmost-bottom pointt
Given n distinct points P1, P2, ..., Pn with the coordinates (x1, y1), (x2, y2), ..., (xn, yn) respectively, write an insertion-sort based algorithm and the corresponding code to arrange the points in an increasing order of their distance from the point  which has smallest x-cordinates, among the given points.  In case, if there are two points with smallest x-coordinate, then you have to choose the point with the smallest y-coordinate and find the diatance of this point from the other points and then sort in an increasing order.     origin (with (0, 0)).   Distance between any two points (a1, b1) and (a2, b2) is

- Input format:
    ```
    Enter the number of point’s n
    Enter the first point x−coordinate
    Enter the first point y−coordinate
    Enter the second point x−coordinate
    Enter the second point y−coordinate
    .....
    Enter the n-th point x−coordinate
    Enter the n-th point y−coordinate
    ```
- Output format:
    ```
    Sorted , first Points of x−coordinate followed by y−coordinate
    Sorted second Point  of x−coordinate followed by y−coordinate
    .....
    Sorted n-th Point  of x−coordinate followed by y−coordinate
    ```   

- Example:
    - Input:
        ```
        7
        5
        5
        6
        6
        1
        0
        2
        0
        3
        1
        1
        -2
        0
        0
        ```
    - Output:
        ```
        0
        0
        1
        0
        2
        0
        1
        -2
        3
        1
        5
        5
        6
        6
        ```