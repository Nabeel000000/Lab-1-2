#include <stdio.h>
#include <stdlib.h>

struct Edge
{
    int src, dest, w;
};

 
struct Graph
{
    int V, E;
    struct Edge *edge;
};

 
struct Graph *create(int V, int E)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge *)malloc(E * sizeof(struct Edge));
    return graph;
}

 
void print(struct Graph *graph)
{
    printf("Edge List:\n");
    printf("Source -> Destination (weight)\n");
    for (int i = 0; i < graph->E; i++)
    {
        printf("  %d    ->      %d       (%d)\n",
               graph->edge[i].src,
               graph->edge[i].dest,
               graph->edge[i].w);
    }
}

int main()
{
    int V = 4;  
    int E = 5; 

    struct Graph *graph = create(V, E);

    
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].w = 10;
 
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].w = 6;

  
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].w = 5;

 
    graph->edge[3].src = 1;
    graph->edge[3].dest = 2;
    graph->edge[3].w = 15;

 
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].w = 4;

    print(graph);

    return 0;
}
