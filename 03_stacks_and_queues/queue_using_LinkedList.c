#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

typedef struct queue
{
    Node *head;
    Node *tail; 
    int cnt;
} queue;

queue *create()
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;
    q->cnt = 0;
    return q;
}

void enqueue(queue *q, int v)
{
    Node *nNode = (Node *)malloc(sizeof(Node));
    nNode->val = v;
    nNode->next = NULL;

    if (q->head == NULL)
    {
        q->head = nNode;
        q->tail = nNode;
    }
    else
    {
        q->tail->next = nNode;
        q->tail = nNode;
    }
    q->cnt++;
}

int dequeue(queue *q)
{
    if (q->head == NULL)
    {
        printf("Empty\n");
        return 0;
    }

    Node *s = q->head;
    int val = s->val;
    q->head = q->head->next;
    if (q->head == NULL)
    {
        q->tail = NULL;
    }

    free(s);
    q->cnt--;

    return val;
}

int front(queue *q)
{
    if (q->head == NULL)
    {
        printf("Empty\n");
        return 0;
    }
    return q->head->val;
}

void display(queue *q)
{
    if (q->head == NULL)
    {
        printf("Empty\n");
        return;
    }

    Node *s = q->head;
    printf("Queue: ");
    while (s != NULL)
    {
        printf("%d -> ", s->val);
        s = s->next;
    }
    printf("NULL\n");
}

int size(queue *q)
{
    return q->cnt;
}

int isEmpty(queue *q)
{
    return q->head == NULL;
}

void free_queue(queue *q)
{
    Node *s;
    while (q->head != NULL)
    {
        s = q->head;
        q->head = q->head->next;
        free(s);
    }
    free(q);
}

int main()
{
    queue *q = create();

    printf("Enqueueing 10, 20, 30\n");
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    display(q);

    printf("Front element: %d\n", front(q));

    printf("Dequeued: %d\n", dequeue(q));
    display(q);

    printf("Size = %d\n", size(q));
    printf("isEmpty = %d\n", isEmpty(q));

    free_queue(q);
    return 0;
}
