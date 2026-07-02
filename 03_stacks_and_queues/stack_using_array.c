#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int *val;       
    int cnt;       
    int size;    
} stack;

stack *create(int s) 
{
    stack *S = (stack *)malloc(sizeof(stack));    
    S->val = (int *)malloc(s * sizeof(int));
    S->cnt = 0;
    S->size = s;
    return S;
}

void push(stack *S, int v)
{
    if (S->cnt == S->size)
    {
        printf("Full\n");
        return;
    }

    S->val[S->cnt] = v;  
    S->cnt++;            
}

int pop(stack *S)
{
    if (S->cnt == 0)
    {
        printf("Empty\n");
        return 0;
    }
    S->cnt--;      
    int val = S->val[S->cnt];
    return val;
}

int top(stack *S)
{
    if (S->cnt == 0)
    {
        printf("Empty\n");
        return 0;
    }
    return S->val[S->cnt - 1];
}

int size(stack *S)
{
    return S->cnt;
}

int isEmpty(stack *S)
{
    return S->cnt == 0;
}

void free_s(stack *S)
{
    if (S != NULL)
    {
        free(S->val);
        free(S);
    }
}

int main()
{
    stack *S = create(5); 

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
