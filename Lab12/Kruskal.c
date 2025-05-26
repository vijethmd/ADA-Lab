#include<stdio.h>
#define MAX 100

struct Edge 
{
    int u,v,weight;
};

int find(int parent[],int i)
{
    if(parent[i] == i) return i;
    else
    {
        return parent[i] = find(parent,parent[i]);
    }
}

void sortEdges(struct Edge edges[],int e)
{
    for(int i = 0;i < e-1;i++)
    {
        for(int j = i+1;j < e;j++)
        {
            if(edges[i].weight > edges[j].weight)
            {
                struct Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }
}

void unionSets(int parent[],int u,int v)
{
    int setU = find(parent,u);
    int setV = find(parent,v);
    parent[setV] = setU;
}
void kruskal(struct Edge edges[],int v,int e)
{
    int parent[MAX];
    struct Edge ET[MAX];
    int total = 0;
    for(int i = 0;i < v;i++)
    {
        parent[i] = i;
    }
    sortEdges(edges,e);
    int encounter = 0,k = -1;
    while(encounter < v - 1)
    {
        k++;
        int u = edges[k].u;
        int w = edges[k].v;
        if(find(parent,u) != find(parent,w))
        {
            ET[encounter] = edges[k];
            unionSets(parent,u,w);
            encounter++;
            total += edges[k].weight;
        }
    }
    printf("\nEdge\tWeight\n");
    for(int i = 0;i<encounter;i++)
    {
        printf("\n%d - %d\t%d",ET[i].u,ET[i].v,ET[i].weight);
    }
    printf("\nTotal Cost : %d ",total);
}

int main()
{
    int v,e;
    
    printf("\nEnter number of edges and vertices : ");
    scanf("%d %d",&e,&v);
    struct Edge edges[e];
    printf("\nEnter edges \nSource\tDest\tWeight\n");
    for(int i = 0;i < e;i++)
    {
        scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].weight);
    }
    kruskal(edges,v,e);
    return 0;
}
