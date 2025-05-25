#include<stdio.h>
#define MAX 10

int max(int a,int b)
{
    return a>b?a:b;
}

int knapsack(int wt[MAX],int val[MAX],int n, int W)
{
    int dp[n + 1][W + 1];
    for(int i = 0;i <= n;i++)
    {
        for(int j = 0;j <= W;j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if(j >= wt[i - 1])
            {
                dp[i][j] = max(dp[i -1][j],val[i - 1] + dp[i - 1][j - wt[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i -1][j];
            }
        }
    }
    return dp[n][W];
}

int main()
{
    int n;
    printf("\nEnter number of objects : ");
    scanf("%d",&n);
    int wt[MAX];
    int val[MAX];
    printf("\nEnter weights : ");
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&wt[i]);
    }
    printf("\nEnter values : ");
    for(int j = 0;j < n;j++)
    {
        scanf("%d",&val[j]);
    }
    int W;
    printf("\nEnter Max Capacity : ");
    scanf("%d",&W);
    int maxProfit = knapsack(wt,val,n,W);
    printf("\n Maximum Profit : %d",maxProfit);
}
