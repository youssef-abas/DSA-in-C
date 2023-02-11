#include <stdio.h>
#include <stdlib.h>

#include <time.h>

int *arr;

int fib(int n);
int fib_arr(int n);
int fib_alt(int n, int p, int pp);

int main(int argc, char **argv)
{
    int N = atoi(argv[1]);
    arr = malloc(sizeof(int) * (N + 1));
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= N; i++)
        arr[i] = -1;

    int begin = time(NULL);
    int end;
    printf("%d\n", fib_alt(N, 0, 1));
    end = time(NULL) - begin;
    printf("In %d seconds!\n", end);

    begin = time(NULL);
    printf("%d\n", fib_arr(N));
    end = time(NULL) - begin;
    printf("In %d seconds!\n", end);

    begin = time(NULL);
    printf("%d\n", fib(N));
    end = time(NULL) - begin;
    printf("In %d seconds!\n", end);
}

int fib(int n)
{
    if (n <= 1)
        return n;

    return fib(n - 1) + fib(n - 2);
}

int fib_alt(int n, int p, int pp)
{
    if (n == 0)
        return p;
    if (n == 1)
        return pp;

    return fib_alt(n - 1, pp, pp + p);
}

int fib_arr(int n)
{
    int t;
    if (arr[n] != -1)
        return arr[n];
    if (n == 0)
        t = 0;
    if (n == 1)
        t = 1;

    if (n > 1)
        t = fib_arr(n - 1) + fib_arr(n - 2);
    return (arr[n] = t);
}