#include <stdio.h>
#include <stdlib.h>

#include <time.h>

#define LEN 10

int find_max_r(int *arr, int len, int i);
int find_max_r_alt(int *arr, int start, int end);

int main()
{
    srand(time(NULL));

    int arr[LEN];
    for (int i = 0; i < LEN; i++)
    {
        arr[i] = rand() % (LEN * 2) - LEN;
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("%d\n", find_max_r_alt(arr, 0, LEN - 1));
}

int find_max_r(int *arr, int len, int i)
{
    if (i == len - 1)
        return arr[i];

    int max_next = find_max_r(arr, len, i + 1);
    return (arr[i] > max_next) ? arr[i] : max_next;
}

int find_max_r_alt(int *arr, int start, int end)
{
    if (start == end)
        return arr[start];

    int mid = (end + start) / 2;
    int max_l = find_max_r_alt(arr, start, mid);
    int max_r = find_max_r_alt(arr, mid + 1, end);

    return (max_l > max_r) ? max_l : max_r;
}