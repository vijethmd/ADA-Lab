#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct item 
{
    int weight;
    int val;
};

void sortitems(struct item items[MAX],int n)
{
    for(int i = 0;i < n-1;i++)
    {
        for(int j = i+1;j < n ;j++)
        {
            float r1 = (float)items[i].val/items[i].weight;
            float r2 = (float)items[j].val/items[j].weight;
            if(r1 < r2)
            {
                struct item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

float fractionalKnapsack(struct item items[MAX],int n,int W)
{
    sortitems(items,n);
    int currentWeight = 0;
    float totalValue = 0.0f;
    for(int i = 0;i<n;i++)
    {
        if(currentWeight + items[i].weight <= W)
        {
            currentWeight += items[i].weight;
            totalValue += items[i].val;
        }
        else
        {
            int remaining = W - currentWeight;
            float r = (float)remaining/items[i].weight;
            float fp = items[i].val * r;
            totalValue += fp;
            break;
        }
        
    }
    return totalValue;
}

int main()
{
    int n;
    int W;
    struct item items[MAX];
    printf("\nEnter number of objects : ");
    scanf("%d",&n);
    printf("\nEnter weights : ");
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&items[i].weight);
    }
    printf("\nEnter profits : ");
    for(int j = 0;j < n;j++)
    {
        scanf("%d",&items[j].val);
    }
    printf("\nEnter Capacity : ");
    scanf("%d",&W);
    float maxProfit = fractionalKnapsack(items,n,W);
    printf("\nMaximum Profit : %.6f",maxProfit);
}
