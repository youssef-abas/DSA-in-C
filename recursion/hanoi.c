#include <stdio.h>
#include <stdlib.h>

void hanoi(int, int, int);
void hanoi_alt(int N, int d);

int main(int argc, char **argv)
{
    hanoi(atoi(argv[1]), 1, 2);
}

void hanoi(int N, int start, int end)
{
    if (N == 1)
    {
        printf("Move disk from rod %d to rod %d\n", start, end);
        return;
    }

    int aux = 6 - (start + end);
    hanoi(N - 1, start, aux);
    printf("Move disk from rod %d to rod %d\n", start, end);
    hanoi(N - 1, aux, end);
}

void hanoi_alt(int N, int d)
{
    if (N == 0)
        return;

    hanoi_alt(N - 1, -d);
    printf("Mode disk %d %d positions\n", N, d);
    hanoi_alt(N - 1, -d);
}