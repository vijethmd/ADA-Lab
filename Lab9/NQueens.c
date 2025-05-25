#include <stdio.h>
#define MAX 20

int N;
int board[MAX][MAX];
int solutionCount = 0;

int isSafe(int row, int col, int N)
{
    for(int i = 0; i < col; i++)
        if(board[row][i]) return 0;

    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(board[i][j]) return 0;

    for(int i = row, j = col; i < N && j >= 0; i++, j--)
        if(board[i][j]) return 0;

    return 1;
}

void printSolution()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
}

void solveNQueens(int col)
{
    if(col == N)
    {
        solutionCount++;
        printf("\nSolution %d:\n", solutionCount);
        printSolution();
        return;
    }

    for(int row = 0; row < N; row++)
    {
        if(isSafe(row, col, N))
        {
            board[row][col] = 1;
            solveNQueens(col + 1);
            board[row][col] = 0; // backtrack
        }
    }
}



int main()
{
    printf("Enter the number of rows and columns: ");
    scanf("%d", &N);

    if(N < 1 || N > MAX)
    {
        printf("Invalid board size.\n");
        return 1;
    }

    // Initialize board
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            board[i][j] = 0;

    solveNQueens(0);

    if(solutionCount == 0)
        printf("\nNo solutions possible for N = %d\n", N);
    else
        printf("\nTotal Solutions: %d\n", solutionCount);

    return 0;
}
