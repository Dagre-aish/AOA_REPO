#include <stdio.h>
#include <stdlib.h>

#define MAX_N 20

int n;
int board[MAX_N];

long long placementsTried = 0;
long long backtracks = 0;
int solutionCount = 0;

int **solutions = NULL;
int solutionCapacity = 0;

int isSafe(int row, int col)
{
    int i;

    for (i = 0; i < col; i++)
    {
        if (board[i] == row)
            return 0;

        if (abs(board[i] - row) == abs(i - col))
            return 0;
    }

    return 1;
}

void storeSolution()
{
    int i;
    int newCapacity;

    if (solutionCount >= solutionCapacity)
    {
        if (solutionCapacity == 0)
            newCapacity = 10;
        else
            newCapacity = solutionCapacity * 2;

        solutions = realloc(solutions, newCapacity * sizeof(int *));

        for (i = solutionCapacity; i < newCapacity; i++)
            solutions[i] = malloc(n * sizeof(int));

        solutionCapacity = newCapacity;
    }

    for (i = 0; i < n; i++)
        solutions[solutionCount][i] = board[i];

    solutionCount++;
}

void displayBoard(int solution[])
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (solution[j] == i)
                printf(" Q ");
            else
                printf(" . ");
        }

        printf("\n");
    }
}

void displayMatrix(int solution[])
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (solution[j] == i)
                printf("1 ");
            else
                printf("0 ");
        }

        printf("\n");
    }
}

void solve(int col)
{
    int row;

    if (col == n)
    {
        storeSolution();

        printf("\nSolution %d found\n", solutionCount);
        displayBoard(board);

        return;
    }

    for (row = 0; row < n; row++)
    {
        placementsTried++;

        printf("\nTrying Row %d, Column %d",
               row + 1, col + 1);

        if (isSafe(row, col))
        {
            board[col] = row;

            printf(" -> Placed\n");

            solve(col + 1);

            printf("Backtrack: Row %d, Column %d\n",
                   row + 1, col + 1);

            board[col] = -1;
            backtracks++;
        }
        else
        {
            printf(" -> Not Safe\n");
        }
    }
}

void freeSolutions()
{
    int i;

    for (i = 0; i < solutionCount; i++)
        free(solutions[i]);

    free(solutions);
}

int main()
{
    int i;

    printf("N-Queen Placement Simulator\n");

    printf("\nEnter board size N: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_N)
    {
        printf("\nInvalid board size.\n");
        printf("Enter N between 1 and %d.\n", MAX_N);
        return 0;
    }

    for (i = 0; i < MAX_N; i++)
        board[i] = -1;

    printf("\nBoard Size: %d x %d\n", n, n);
    printf("Starting Backtracking...\n");

    solve(0);

    printf("\nFinal Result\n");

    if (solutionCount == 0)
    {
        printf("\nNo solution exists for N = %d.\n", n);
    }
    else
    {
        printf("\nTotal Number of Solutions: %d\n",
               solutionCount);

        for (i = 0; i < solutionCount; i++)
        {
            printf("\nSolution %d\n", i + 1);

            printf("\nChessboard:\n");
            displayBoard(solutions[i]);

            printf("\nMatrix:\n");
            displayMatrix(solutions[i]);
        }
    }

    printf("\nAlgorithm Statistics\n");
    printf("Board Size       : %d x %d\n", n, n);
    printf("Solutions Found  : %d\n", solutionCount);
    printf("Placements Tried : %lld\n", placementsTried);
    printf("Backtracks       : %lld\n", backtracks);

    freeSolutions();

    return 0;
}
