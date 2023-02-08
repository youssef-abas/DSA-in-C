#include <stdio.h>

int main()
{
    int *arr = {1, 2, 3};
}

void print_perm(int *arr, int n, int r)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
        print_perm(arr, n, r - 1);
    }
}