#include <stdio.h>
#include <stdlib.h>

#include "../sorting/sort.h"

int binary_search_r(int *arr, int v, int low, int high)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == v)
        return mid;

    if (v > arr[mid])
        binary_search_r(arr, v, mid + 1, high);
    else
        binary_search_r(arr, v, low, mid - 1);
}

int main(int argc, char **argv)
{
    int arr[] = {-35, 12, 122, 912, -1004, 0, 43, 1, 2, 3, -1};
    merge_sort(arr, 0, 10);

    printf("Item found in position: %d\n", binary_search_r(arr, atoi(argv[1]), 0, 11));
}