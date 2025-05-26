#include<stdio.h>
#define MAX 10
#define LEFT -1
#define RIGHT 1

int getMobile(int perm[],int dir[],int n)
{
    int max = 0;
    int minIdx = -1;
    for(int i = 0;i < n;i++)
    {
        int next = i + dir[i];
        if(next >= 0 && next < n && perm[next] < perm[i] && perm[i] > max)
        {
            max = perm[i];
            minIdx = i;
        }
    }
    return minIdx;
}

void printPerm(int perm[],int n)
{
    for(int i = 0;i < n;i++)
    {
        printf("%d ",perm[i]);
    }
    printf("\n");
}

void johnsonTrotter(int n)
{
    int perm[MAX];
    int dir[MAX];
    for(int i = 0;i<n;i++)
    {
        perm[i] = i+1;
        dir[i] =LEFT;
    }
    printPerm(perm,n);
    while(1)
    {
        int mobileIdx = getMobile(perm,dir,n);
        if(mobileIdx == -1) break;
        int swapIdx = mobileIdx + dir[mobileIdx];
        
        
        int temp = perm[mobileIdx];
        perm[mobileIdx] = perm[swapIdx];
        perm[swapIdx] = temp;
        
        
        temp = dir[mobileIdx];
        dir[mobileIdx] = dir[swapIdx];
        dir[swapIdx] = temp;
        
        
        mobileIdx = swapIdx;
        
        for(int i = 0;i < n;i++)
        {
            if(perm[i] > perm[mobileIdx])
            {
                dir[i] = -dir[i];
            }
        }
        printPerm(perm,n);
    }
}

int main()
{
    int n;
    printf("\nEnter the number of elements : ");
    scanf("%d",&n);
    johnsonTrotter(n);
}
