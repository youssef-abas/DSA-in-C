#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int val;
} Item;

Item items[5] = {{3, 4}, {4, 5}, {7, 10}, {8, 11}, {9, 13}};
int N = 5;
int *F;

int knap_alt(int M);
int knap_alt_dp(int M);
int knapsack(int cap, int i);
int max(int x1, int x2, int x3);

int main(int argc, char **argv)
{
    int M = atoi(argv[1]);
    F = malloc(sizeof(int) * (M + 1));
    for (int i = 0; i <= M; i++)
        F[i] = -1;

    printf("Maximum take is %d\n", knap_alt_dp(M));
    printf("Maximum take is %d\n", knapsack(M, N - 1));
    printf("Maximum take is %d\n", knap_alt(M));
}

int knapsack(int cap, int i)
{
    int t1 = 0, t2, t3 = 0;
    int newcap = cap - items[i].size;
    if (newcap == 0)
        return items[i].val;

    if (cap == 0)
        return 0;

    if (i == 0)
        if (newcap < 0)
            return 0;
        else
            return items[i].val + knapsack(newcap, i);

    if (newcap > 0)
    {
        t1 = items[i].val + knapsack(newcap, i);
        t3 = items[i].val + knapsack(newcap, i - 1);
    }
    t2 = knapsack(cap, i - 1);

    return max(t1, t2, t3);
}

int knap_alt(int M)
{
    int i, space, max, t;
    for (i = 0, max = 0; i < N; i++)
    {
        if ((space = M - items[i].size) >= 0)
            if ((t = knap_alt(space) + items[i].val) > max)
                max = t;
    }
    return max;
}

int knap_alt_dp(int M)
{
    if (F[M] != -1)
        return F[M];

    int i, space, max, maxi, t;
    for (i = 0, max = 0; i < N; i++)
    {
        if ((space = M - items[i].size) >= 0)
            if ((t = knap_alt_dp(space) + items[i].val) > max)
                max = t;
    }
    return (F[M] = max);
}

int max(int x1, int x2, int x3)
{
    if (x1 > x2)
    {
        if (x1 > x3)
        {
            return x1;
        }
        else
        {
            return x3;
        }
    }
    else if (x2 > x3)
    {
        return x2;
    }
    else
    {
        return x3;
    }
}