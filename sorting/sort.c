#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *arr, int len, int dec)
{
    for (int i = 1; i < len; i++)
    {
        int unsorted = arr[i];
        int j = i - 1;
        while (j >= 0)
        {
            if (dec && arr[j] > unsorted)
                break;
            if (!dec && arr[j] < unsorted)
                break;
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = unsorted;
    }
}

void selection_sort(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        int smallest_j = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[smallest_j])
                smallest_j = j;
        }
        int temp = arr[i];
        arr[i] = arr[smallest_j];
        arr[smallest_j] = temp;
    }
}

void merge(int *arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int *l_arr = malloc(sizeof(int) * n1);
    int *r_arr = malloc(sizeof(int) * n2);
    int i, j;

    for (i = 0; i < n1; i++)
        l_arr[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        r_arr[j] = arr[m + j + 1];

    i = j = 0;
    int k = l;
    while (k < r && i < n1 && j < n2)
    {
        if (l_arr[i] <= r_arr[j])
        {
            arr[k] = l_arr[i++];
        }
        else
        {
            arr[k] = r_arr[j++];
        }
        k++;
    }

    while (i < n1)
        arr[k++] = l_arr[i++];

    while (j < n2)
        arr[k++] = r_arr[j++];

    free(l_arr);
    free(r_arr);
}

void merge_sort(int *arr, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    int arr[] = {-35, 12, 122, 912, -1004, 0, 43, 1, 2, 3, -1};

    merge_sort(arr, 0, 10);

    for (int i = 0; i < 11; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}