#include <stdio.h>
#include <stdlib.h>

struct N
{
    int vertex;
    struct N *next;
};

struct list
{
    struct N *head;
};

struct Graph
{
    int cntV;
    struct list *arr;
};

struct N *createN(int v)
{
    struct N *nNode = (struct N *)malloc(sizeof(struct N));
    nNode->vertex = v;
    nNode->next = NULL;
    return nNode;
}

struct Graph *create(int n)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->cntV = n;
    graph->arr = (struct list *)malloc(n * sizeof(struct list));

    for (int i = 0; i < n; ++i)
        graph->arr[i].head = NULL;

    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    struct N *nNode = createN(dest);
    nNode->next = graph->arr[src].head;
    graph->arr[src].head = nNode;

    nNode = createN(src);
    nNode->next = graph->arr[dest].head;
    graph->arr[dest].head = nNode;
}

void printGraph(struct Graph *graph)
{
    printf("Adjacency List:\n");
    for (int v = 0; v < graph->cntV; ++v)
    {
        struct N *temp = graph->arr[v].head;
        printf("\n Vertex %d: ", v);
        while (temp)
        {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int V = 4;
    struct Graph *graph = create(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printGraph(graph);

    return 0;
}
