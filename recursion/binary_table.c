#include <stdlib.h>
#include <stdio.h>

void print_tab(int n, char *, int);
void print_table(int n, char *num, int len);
void print_binum(int n);

int main(int argc, char **argv)
{
    int N = atoi(argv[1]) + 1;
    char *num = malloc(N);

    print_table(atoi(argv[1]), num, N - 1);
}

void print_table(int n, char *num, int len)
{
    if (n == 0)
    {
        num[len] = '\0';
        printf("%s\n", num);
        return;
    }

    num[len - n] = '0';
    print_table(n - 1, num, len);
    num[len - n] = '1';
    print_table(n - 1, num, len);
}

void print_binum(int n)
{
    if (n / 2 == 0)
        printf("%d", n);
    else
    {
        print_binum(n / 2);
        printf("%d", n % 2);
    }
}

// void print_tab(int n, char *num, int len)
// {
//     print_table(n - 1, 0, num, len);
//     print_table(n - 1, 1, num, len);
// }