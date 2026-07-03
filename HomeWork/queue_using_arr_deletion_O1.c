#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int *val;
    int cnt;
    int size;
} queue;

queue *create(int s)
{
    queue *Q = (queue *)malloc(sizeof(queue));
    Q->val = (int *)malloc(s * sizeof(int));
    Q->cnt = 0;
    Q->size = s;
    return Q;
}

void enqueue(queue *Q, int v)
{
    if (Q->cnt == Q->size)
    {
        printf("Full\n");
        return;
    }
    for (int i = Q->cnt; i > 0; i--)
    {
        Q->val[i] = Q->val[i - 1];
    }

    Q->val[0] = v;
    Q->cnt++;
}

int dequeue(queue *Q)
{
    if (Q->cnt == 0)
    {
        printf("Empty\n");
        return 0;
    }
    Q->cnt--;
    int val = Q->val[Q->cnt];
    return val;
}

int front(queue *Q)
{
    if (Q->cnt == 0)
    {
        printf("Empty\n");
        return 0;
    }
    return Q->val[Q->cnt - 1];
}

int size(queue *Q)
{
    return Q->cnt;
}

int isEmpty(queue *Q)
{
    return Q->cnt == 0;
}

void display(queue *Q)
{
    if (Q->cnt == 0)
    {
        printf("Empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = Q->cnt - 1; i >= 0; i--)
    {
        printf("%d -> ", Q->val[i]);
    }
    printf("NULL'\n");
}

void free_q(queue *Q)
{
    if (Q != NULL)
    {
        free(Q->val);
        free(Q);
    }
}

int main()
{
    queue *Q = create(5);

    enqueue(Q, 4);
    enqueue(Q, 5);
    enqueue(Q, 1);
    enqueue(Q, 2);

    display(Q);

    printf("Front = %d\n", front(Q));
    printf("Dequeued = %d\n", dequeue(Q)); 

    display(Q);
    printf("Front = %d\n", front(Q));  
    printf("Size = %d\n", size(Q));
    printf("isEmpty = %d\n", isEmpty(Q));

    free_q(Q);

    return 0;
}
