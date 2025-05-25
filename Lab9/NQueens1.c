#include<stdio.h>
#define MAX 20
int N;
int board[MAX][MAX];

int isSafe(int row,int col,int N)
{
    for(int i = 0;i<col;i++)
    {
        if(board[row][i]) return 0;
    }
    for(int i = row,j = col;i >= 0 && j >= 0;i--,j--)
    {
        if(board[i][j]) return 0;
    }
    for(int i = row,j = col;i>=0 && j < N;i--,j++)
    {
        if(board[i][j]) return 0;
    }
    
    return 1;
}

int solveNQueens(int i)
{
    if(i == N) return 1;
    for(int row = 0;row < N;row++)
    {
        if(isSafe(row,i,N))
        {
            board[row][i] = 1;
            
            if(solveNQueens(i + 1)) return 1;
            
            board[row][i] = 0;
        }
    }
    return 0;
}

void printSolution()
{
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j < N;j++)
        {
            if(board[i][j]) printf("Q ");
            else printf(". ");
        }
        printf("\n");
    }
}

int main()
{
    printf("\nEnter the number of rows and columns : ");
    scanf("%d",&N);
    
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < N;j++)
        {
            board[i][j] = 0;
        }
    }
    
    if(solveNQueens(0))
    {
        printSolution();
    }
    else
    {
        printf("\nNo solutions possible for %d",N);
    }
}
