#include <stdio.h>
#include <stdlib.h>

typedef struct S
{
    char *str;
    int size, n;
} S;

void push_back(S *s, char c)
{
    if (s->size == s->n)
    {
        s->str = (char *)realloc(s->str, sizeof(char) * 2 * s->size);
        s->size *= 2;
    }
    s->str[s->n++] = c;
}

void create(S *s, char c[])
{
    int sz = 0;
    while (c[sz] != '\0')
        sz++;
    s->str = (char *)malloc(sz * sizeof(char) * 2 + 1);
    s->size = sz * 2 + 1;
    s->n = 0;
    for (int i = 0; i < sz; i++)
        push_back(s, c[i]);
}

void pop_back(S *s)
{
    if (s->n == 0)
        return;
    s->n--;
}

int size(S *s)
{
    return s->n;
}

char at_index(S *s, int in)
{
    return s->str[in];
}

void clear(S *s)
{
    s->n = 0;
}

void concat(S *m, S *pat)
{
    int i = 0;
    while (i < size(pat))
        push_back(m, pat->str[i++]);
}

void display(S *s)
{
    int i = 0;
    while (i < size(s))
        printf("%c", at_index(s, i++));
    printf("\n");
}

void insert_at(S *s, char c, int in)
{
    if (in < 0 || in > s->n)
        return;
    push_back(s, c);
    for (int i = size(s) - 2; i >= in; i--)
    {
        s->str[i + 1] = s->str[i];
    }
    s->str[in] = c;
}

void delete_at(S *s, int in)
{
    if (in < 0 || in >= s->n)
        return;
    for (int i = in; i < size(s) - 1; i++)
    {
        s->str[i] = s->str[i + 1];
    }
    s->n--;
}
void replace_at(S *s, char c, int in)
{
    if (in < 0 || in >= s->n)
        return;
    s->str[in] = c;
}

int find_substring(S *s, S *pat)
{
    int n = s->n;
    int m = pat->n;

    if (m > n || m == 0)
    {
        return -1;
    }
    for (int i = 0; i <= n - m; i++)
    {
        int j = -1;
        for (j = 0; j < m; j++)
        {
            if (s->str[i + j] != pat->str[j])
            {
                break;
            }
        }
        if (j == m)
        {
            return i;
        }
    }
    return -1;
}

void Free(S *s)
{
    if (s->str)
    {
        free(s->str);
        s->str = NULL;
    }
    s->size = 0;
    s->n = 0;
}

int main()
{
    S s1, s2;
    create(&s1, "Abdullah");
    create(&s2, "Nabeel");
    display(&s1);
    concat(&s1, &s2);
    display(&s1);
    insert_at(&s1, ' ', 8);
    display(&s1);
    delete_at(&s1, 8);
    display(&s1);
    printf("substring index is:%d\n", find_substring(&s1, &s2));
    Free(&s1);
    Free(&s2);
    return 0;
}
