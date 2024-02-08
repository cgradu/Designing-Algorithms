# Designing Algorithms

## Author: Constantin Radu-Giorgian

This repository contains solutions for various problems implemented in C++ as part of the Advanced Programming course.

### Problem 1 - feribot.cpp:
The implementation utilizes binary search to find the optimal solution for ferry loading.

- **Complexities**:
  - Time: O(N*log(S)), where N is the number of cars and S is the total weight of all cars.
  - Space: O(N)

### Problem 2 - nostory.cpp:

**Task 1:**
Sorting a vector to identify maximum values from both sides.

- **Complexities**:
  - Time: O(N*log(N)), where N is the size of the vector.
  - Space: O(N)

**Task 2:**
Using two vectors to store maximum and minimum values, facilitating swapping to ensure the resulting vectors have necessary elements.

- **Complexities**:
  - Time: O(N*log(N)), where N is the size of the vector.
  - Space: O(N)

### Problem 3 - sushi.cpp:

**Task 1 + Task 2:**
Dynamic programming approach similar to the knapsack problem is employed.

- **Complexities**:
  - Time: O((M+1)^2) due to calculating solutions in the dp vector.
  - Space: O((M+1)^2) due to the dp vector.

**Task 3:**
Attempted solution similar to Task 2 with additional logic to track when all 'n' plates have been taken.

### Problem 4 - semnale.cpp:
No attempted implementation.

### Problem 5 - badgpt.cpp:
Using the Fibonacci matrix to determine the number of possible combinations for the given sequence.

- **Complexity**:
  - Time: O(N), where N is the maximum number.
  - Space: O(KMAX^2) due to the Fibonacci matrix, where KMAX is the size of a row/column in the matrix.

**Additional Sources**:
- https://www.geeksforgeeks.org/
- https://stackoverflow.com/
- https://www.wikipedia.org/
- https://www.programiz.com/
