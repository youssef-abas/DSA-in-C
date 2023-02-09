#include <stdlib.h>
#include <stdio.h>

void print_table(int n, int b);

int main(int argc, char **argv)
{
    print_table(atoi(argv[1]), 0);
}

void print_table(int n, int b)
{
    if (n == 0)
    {
        printf("\n");
        return;
    }

    print_table(n - 1, 0);
    print_table(n - 1, 1);
}