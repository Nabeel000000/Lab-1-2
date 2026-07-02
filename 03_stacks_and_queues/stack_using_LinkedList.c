#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

typedef struct stack
{
    Node *head;
    int cnt;
} stack;

stack *create()
{
    stack *S = (stack *)malloc(sizeof(stack));
    S->head = NULL;
    S->cnt = 0;
    return S;
}

void push(stack *S, int v)
{
    Node *nNode = (Node *)malloc(sizeof(Node));
    nNode->val = v;
    nNode->next = S->head;
    S->head = nNode;
    S->cnt++;
}

int pop(stack *S)
{
    if (S->head == NULL)
    {
        printf("Empty\n");
        return 0;
    }
    int val = S->head->val;
    Node *s = S->head;
    S->head = S->head->next;
    free(s);
    S->cnt--;
    return val;
}

int top(stack *S)
{
    if (S->head == NULL)
    {
        printf("Empty\n");
        return 0;
    }
    return S->head->val;
}

int size(stack *S)
{
    return S->cnt;
}

int isEmpty(stack *S)
{
    return S->head == NULL;
}

void free_s(stack *S)
{
    Node *temp;

    while (S->head != NULL)
    {
        temp = S->head;
        S->head = S->head->next;
        free(temp);
    }

    free(S);
}

int main()
{
    stack *S = create();

    push(S, 4);
    push(S, 5);
    push(S, 1);
    push(S, 2);

    printf("Top = %d\n", top(S));
    pop(S);
    printf("Top = %d\n", top(S));

    printf("Size = %d\n", size(S));
    printf("isEmpty = %d\n", isEmpty(S));
    printf("Popped = %d\n", pop(S));

    free_s(S);

    return 0;
}
