#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *arr;
    int size;
    int capacity;
} Heap;

Heap *create(int capacity)
{
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->capacity = capacity;
    h->size = 0;
    h->arr = (int *)malloc(capacity * sizeof(int));
    return h;
}

int parent(int i) { return (i - 1) / 2; }
int left_child(int i) { return (2 * i) + 1; }
int right_child(int i) { return (2 * i) + 2; }

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sift_up(Heap *h, int i)
{
    while (i != 0 && h->arr[parent(i)] < h->arr[i])
    {
        swap(&h->arr[i], &h->arr[parent(i)]);
        i = parent(i);
    }
}

void insert(Heap *h, int value)
{
    if (h->size == h->capacity)
    {
        printf("h is full. Cannot insert %d\n", value);
        return;
    }

    int i = h->size;
    h->arr[i] = value;
    h->size++;

    sift_up(h, i);
}

void sift_down(Heap *h, int i)
{
    int largest = i;
    int left = left_child(i);
    int right = right_child(i);

    if (left < h->size && h->arr[left] > h->arr[largest])
    {
        largest = left;
    }
    if (right < h->size && h->arr[right] > h->arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(&h->arr[i], &h->arr[largest]);
        sift_down(h, largest);
    }
}

int extract_max(Heap *h)
{
    if (h->size <= 0)
    {
        printf("h is empty!\n");
        return -1;
    }
    if (h->size == 1)
    {
        h->size--;
        return h->arr[0];
    }

    int root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    sift_down(h, 0);
    return root;
}

void print_h(Heap *h)
{
    for (int i = 0; i < h->size; i++)
    {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}
void free_heap(Heap *h)
{
    free(h->arr);
    free(h);
}
int main()
{
    Heap *h = create(10);

    insert(h, 10);
    insert(h, 20);
    insert(h, 15);
    insert(h, 40);
    insert(h, 50);
    insert(h, 100);

    printf("h arr after insertions: ");
    print_h(h);

    printf("Extracted max: %d\n", extract_max(h));

    printf("h arr after extraction: ");
    print_h(h);

    free_heap(h);
    return 0;
}
