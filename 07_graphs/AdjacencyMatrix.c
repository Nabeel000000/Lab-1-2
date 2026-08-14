#include <stdio.h>

#define V 4

void Matrix(int matrix[V][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void addEdge(int matrix[V][V], int i, int j)
{
    matrix[i][j] = 1;
    matrix[j][i] = 1;
}

void print(int matrix[][V])
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int adjMatrix[V][V];

    Matrix(adjMatrix);

    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 0, 3);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 2, 3);

    print(adjMatrix);

    return 0;
}
