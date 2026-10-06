# Analysis of Algorithms

## N-Queen Problem

- Implemented using **Backtracking**
- Checks row and diagonal conflicts
- Displays all possible solutions
- Shows the chessboard and matrix representation
- Displays basic algorithm statistics such as placements tried and backtracks

**File:** `nqueen.c`

## Approach

For the N-Queen problem, the backtracking approach works by:

1. Placing a queen column by column.
2. Checking whether the position is safe.
3. Moving to the next column if the position is valid.
4. Removing the queen and trying another position when a solution cannot be continued.

## Time Complexity

**O(N × N!)**

In the worst case, the algorithm explores a large number of possible queen placements, giving approximately **N!** possible arrangements to consider. For each placement, `isSafe()` checks previously placed queens, which can take **O(N)** time. Therefore, the overall worst-case time complexity is **O(N × N!)**.

## Technologies

- **Language:** C
- **Concepts:** Backtracking, Recursion
- **Compiler:** GCC / any standard C compiler
