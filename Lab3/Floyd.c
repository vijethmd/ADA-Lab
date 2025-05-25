#include<stdio.h>
#define MAX 20
#define INF 9999
void floyd(int graph[MAX][MAX],int n)
{
    int dist[MAX][MAX];
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            dist[i][j] = graph[i][j];
        }
    }
    for(int k = 0;k < n;k++)
    {
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printf("\nThe final adjacency matrix : \n");
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            printf("%d ",dist[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("\nEnter the number of vertices : ");
    scanf("%d",&n);
    int graph[MAX][MAX];
    printf("\nEnter adjacency matrix of graph : \n");
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    floyd(graph,n);
}
