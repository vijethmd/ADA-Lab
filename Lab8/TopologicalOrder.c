#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void topologicalsort(int graph[MAX][MAX],int n)
{
    int indegree[n];
    int queue[n*10];
    int rear = 0,front = 0;
    for(int i = 0;i<n;i++)
    {
        indegree[i] = 0;
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if(graph[i][j] > 0)
            {
                indegree[j]++;
            }
        }
    }
    for(int i = 0;i < n;i++)
    {
        if(indegree[i] == 0)
        {
            queue[rear++] = i;
        }
    }
    int topOrder[n];
    int count = 0;
    while(front < rear)
    {
        int u = queue[front++];
        topOrder[count++] = u;
        for(int i = 0;i < n;i++)
        {
            if(graph[u][i] > 0)
            {
                indegree[i]--;
                if(indegree[i] == 0)
                {
                    queue[rear++] = i;
                }
            }
            
        }
    }
    printf("\n");
    if (count != n)
    {
        printf("\nCycle present. Topological Order not possible");
    }
    else
    {
        printf("\nTopological Order : ");
        for(int j = 0;j < n;j++)
        {
            printf(" %d ",topOrder[j]);
        }
    }
}

int main()
{
    int n;
    printf("\nEnter number of vertices : ");
    scanf("%d",&n);
    int graph[MAX][MAX];
    printf("\nEnter adjacency matrix : \n");
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    // int s;
    // printf("\nEnter start index : ");
    // scanf("%d",&s);
    topologicalsort(graph,n);
}
