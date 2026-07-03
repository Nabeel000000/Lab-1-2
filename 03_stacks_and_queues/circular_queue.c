#include <stdio.h>
#include <stdlib.h>

typedef struct CQueue
{
    int *arr;
    int front;
    int rear;
    int cnt;
    int size;
} CQueue;

CQueue *create(int s)
{
    CQueue *CQ = (CQueue *)malloc(sizeof(CQueue));
    CQ->arr = (int *)malloc(s * sizeof(int));
    CQ->front = 0;
    CQ->rear = -1;
    CQ->cnt = 0;
    CQ->size = s;
    return CQ;
}

void enqueue(CQueue *CQ, int v)
{
    if (CQ->cnt == CQ->size)
    {
        printf("Full\n");
        return;
    }

    CQ->rear = (CQ->rear + 1) % CQ->size;
    CQ->arr[CQ->rear] = v;
    CQ->cnt++;
}

int dequeue(CQueue *CQ)
{
    if (CQ->cnt == 0)
    {
        printf("Empty\n");
        return 0;
    }

    int arr = CQ->arr[CQ->front];
    CQ->front = (CQ->front + 1) % CQ->size;
    CQ->cnt--;
    return arr;
}

int front(CQueue *CQ)
{
    if (CQ->cnt == 0)
    {
        printf("Empty\n");
        return 0;
    }
    return CQ->arr[CQ->front];
}

int size(CQueue *CQ)
{
    if (CQ->cnt == 0)
        return 0;
    return (CQ->rear - CQ->front + CQ->size) % CQ->size + 1;
}

int isEmpty(CQueue *CQ)
{
    return CQ->cnt == 0;
}

void display(CQueue *CQ)
{
    if (CQ->cnt == 0)
    {
        printf("Empty\n");
        return;
    }
    printf("CQueue: ");
    for (int i = 0; i < CQ->cnt; i++)
    {
        int index = (CQ->front + i) % CQ->size;
        printf("%d -> ", CQ->arr[index]);
    }
    printf("NULL\n");
}

void free_CQ(CQueue *CQ)
{
    if (CQ != NULL)
    {
        free(CQ->arr);
        free(CQ);
    }
}

int main()
{
    CQueue *CQ = create(5);

    enqueue(CQ, 10);
    enqueue(CQ, 20);
    enqueue(CQ, 30);
    enqueue(CQ, 40);

    printf("dequeued: %d\n", dequeue(CQ));
    printf("dequeued: %d\n", dequeue(CQ));

    enqueue(CQ, 50);
    enqueue(CQ, 60);

    display(CQ);

    printf("Size: %d\n", size(CQ));

    free_CQ(CQ);
    return 0;
}
