#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *l;
    struct Node *r;
    int h;

} Node;
int max(int a, int b)
{
    return a > b ? a : b;
}
int height(Node *n)
{
    if (n == NULL)
        return 0;
    return n->h;
}

Node *create(int v)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = v;
    node->r = NULL;
    node->l = NULL;
    node->h = 1;
    return node;
}

int bf(Node *n)
{
    if (n == NULL)
        return 0;
    return height(n->l) - height(n->r);
}

Node *L_rotate(Node *x)
{
    Node *y = x->r, *t2 = y->l;
    y->l = x;
    x->r = t2;
    x->h = max(height(x->l), height(x->r)) + 1;
    y->h = max(height(y->l), height(y->r)) + 1;
    return y;
}

Node *R_rotate(Node *y)
{
    Node *x = y->l, *t2 = x->r;
    x->r = y;
    y->l = t2;
    y->h = max(height(y->l), height(y->r)) + 1;
    x->h = max(height(x->l), height(x->r)) + 1;
    return x;
}

Node *insert(Node *n, int v)
{
    if (n == NULL)
        return create(v);
    if (n->val < v)
        n->r = insert(n->r, v);
    else
        n->l = insert(n->l, v);
    n->h = max(height(n->l), height(n->r)) + 1;
    // LL
    if (bf(n) > 1 && v < n->l->val)
    {
        n = R_rotate(n);
    }
    // RR
    if (bf(n) < -1 && v > n->r->val)
    {
        n = L_rotate(n);
    }
    // LR
    if (bf(n) > 1 && v > n->l->val)
    {
        n->l = L_rotate(n->l);
        n = R_rotate(n);
    }
    // RL
    if (bf(n) < -1 && v < n->r->val)
    {
        n->r = R_rotate(n->r);
        n = L_rotate(n);
    }
    return n;
}
void preorder(Node *n)
{
    if(n==NULL)return;
    printf("%d ", n->val);
    preorder(n->l);
    preorder(n->r);
}
int main()
{
    Node *root = NULL;
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 1);

    preorder(root);
    return 0;
}
