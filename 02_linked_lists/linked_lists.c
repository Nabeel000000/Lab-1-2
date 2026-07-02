#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

typedef struct LL
{
    Node *head;
    int cnt;
} LL;

LL *create()
{
    LL *list = (LL *)malloc(sizeof(LL));
    list->head = NULL;
    list->cnt = 0;
    return list;
}

void push_front(LL *list, int v)
{
    Node *nNode = (Node *)malloc(sizeof(Node));
    nNode->val = v;
    nNode->next = list->head;
    list->head = nNode;
    list->cnt++;
}

void push_back(LL *list, int v)
{
    Node *nNode = (Node *)malloc(sizeof(Node));
    nNode->val = v;
    nNode->next = NULL;
    if (list->head == NULL)
    {
        list->head = nNode;
    }
    else
    {
        Node *s = list->head;
        while (s->next != NULL)
        {
            s = s->next;
        }
        s->next = nNode;
    }
    list->cnt++;
}

void insert_at(LL *list, int in, int v)
{
    if (in < 0 || in > list->cnt)
    {
        printf("Invalid in\n");
        return;
    }
    if (in == 0)
    {
        push_front(list, v);
        return;
    }
    if (in == list->cnt)
    {
        push_back(list, v);
        return;
    }
    Node *nNode = (Node *)malloc(sizeof(Node));
    nNode->val = v;
    Node *s = list->head;
    for (int i = 0; i < in - 1; i++)
    {
        s = s->next;
    }
    nNode->next = s->next;
    s->next = nNode;
    list->cnt++;
}

int delete_at(LL *list, int in)
{
    if (list->head == NULL)
    {
        printf("Empty\n");
        return 0;
    }
    if (in < 0 || in >= list->cnt)
    {
        printf("Invalid in\n");
        return 0;
    }
    Node *s = list->head;
    if (in == 0)
    {
        int val = list->head->val;
        list->head = list->head->next;
        free(s);
        list->cnt--;
        return val;
    }
    for (int i = 0; i < in - 1; i++)
    {
        s = s->next;
    }
    Node *dNode = s->next;
    int val = dNode->val;
    s->next = dNode->next;
    free(dNode);
    list->cnt--;
    return val;
}

int search(LL *list, int tar)
{
    int in = 0;
    Node *s = list->head;
    while (s != NULL)
    {
        if (s->val == tar)
        {
            return in;
        }
        s = s->next;
        in++;
    }
    return -1;
}

void display(LL *list)
{
    if (list->head == NULL)
    {
        printf("Empty\n");
        return;
    }
    Node *s = list->head;
    printf("List: ");
    while (s != NULL)
    {
        printf("%d -> ", s->val);
        s = s->next;
    }
    printf("NULL\n");
}

int size(LL *list)
{
    return list->cnt;
}

int empty(LL *list)
{
    return list->head == NULL;
}

void free_list(LL *list)
{
    Node *s;
    while (list->head != NULL)
    {
        s = list->head;
        list->head = list->head->next;
        free(s);
    }
    free(list);
}

int main()
{
    LL *list = create();

    push_front(list, 20);
    push_front(list, 10);
    push_back(list, 40);
    push_back(list, 50);
    display(list);

    printf("Inserting 30 at in 2...\n");
    insert_at(list, 2, 30);
 
    display(list);
    printf("in of 40: %d\n", search(list, 40));

    printf("Deleted at in 3: %d\n", delete_at(list, 3));
    display(list);

    printf("Size = %d\n", size(list));
    printf("empty = %d\n", empty(list));

    free_list(list);
    return 0;
}
