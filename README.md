# Analysis of Algorithms (AOA)

A collection of **Analysis of Algorithms** practical programs implemented in C.

## Contents

### 1. N-Queen Problem
- Implemented using **Backtracking**
- Checks row and diagonal conflicts
- Displays all possible solutions
- Shows the chessboard and matrix representation
- Displays basic algorithm statistics such as placements tried and backtracks

**File:** `nqueen.c`

## Approach

The programs in this repository focus on implementing important algorithm design techniques in a simple and practical way.

For the N-Queen problem, the backtracking approach works by:
1. Placing a queen column by column.
2. Checking whether the position is safe.
3. Moving to the next column if the position is valid.
4. Removing the queen and trying another position when a solution cannot be continued.

## Technologies

- **Language:** C
- **Concepts:** Algorithm Design, Backtracking, Recursion
- **Compiler:** GCC / any standard C compiler

## How to Run

Compile the program using:

```bash
gcc nqueen.c -o nqueen
```

Run it using:

```bash
./nqueen
```

On Windows:

```bash
nqueen.exe
```

## Repository

This repository contains practical implementations for the **AOA** subject and will be updated with additional algorithm problems as they are completed.
