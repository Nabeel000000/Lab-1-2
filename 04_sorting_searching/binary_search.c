#include <stdio.h>

int BS(int arr[], int size, int k)
{
    int l = 0, r = size - 1;

    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (arr[m] == k)
            return m;

        if (arr[m] < k)
            l = m + 1;
        else
            r = m - 1;
    }

    return -1;
}

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k;

    printf("Enter the element to search: ");
    scanf("%d", &k);

    int result = BS(arr, size, k);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
