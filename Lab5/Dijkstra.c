#include<stdio.h>
#define MAX 20
#define INF 9999

int minDistance(int visited[MAX],int n,int d[MAX])
{
    int min = INF;
    int minIdx = -1;
    for(int i = 0;i < n;i++)
    {
        if(!visited[i] && d[i] < min )
        {
                min = d[i];
                minIdx = i;
        }
    }
    return minIdx;
}

int dijkstra(int graph[MAX][MAX],int n,int s)
{
    int d[MAX];
    int p[MAX];
    int visited[MAX];
    for(int v = 0;v < n;v++)
    {
        d[v] = INF;
        p[v] = -1;
        visited[v] = 0;
    }
    d[s] = 0;
    for(int count  = 0;count < n;count++)
    {
        int u = minDistance(visited,n,d);
        if(u == -1) break;
        visited[u] = 1;
        
        for(int v = 0;v < n;v++)
        {
            if(!visited[v] && graph[u][v] > 0 && d[u] + graph[u][v] < d[v])
            {
                d[v] = d[u] + graph[u][v];
                p[v] = u;
            }
        }
    }
    printf("\nVertex\tDistance from %d\tPath\n",s);
    for(int i = 0;i<n;i++)
    {
        printf("%d\t%d\t\t",i,d[i]);
        int path[MAX],k = 0;
        int temp = i;
        while(temp != -1)
        {
            path[k++] = temp;
            temp = p[temp];
        }
        for(int i = k - 1;i >= 0;i--)
        {
            printf(" %d ",path[i]);
        }
        printf("\n");
    }
}

int main()
{
    int graph[MAX][MAX];
    int n;
    printf("\nEnter the number of vertices : ");
    scanf("%d",&n);
    printf("\nEnter adjacency matrix : \n");
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    int s;
    printf("\nEnter starting index : ");
    scanf("%d",&s);
    dijkstra(graph,n,s);
}
