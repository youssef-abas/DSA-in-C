#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void draw_rule(int, int, int);
void mark(int, int);

void print_dash(int);

int main(int argc, char **argv)
{
    // system("clear");
    draw_rule(0, (int)pow(2, atoi(argv[1])), atoi(argv[1]));
    // fflush(stdout);
    // while (1)
    //     ;
}

void mark(int x, int h)
{
    printf("Mark a line of height %d at x = %d\n", h, x);
    // printf("\033[4C");
    // print_dash(h);
}

void draw_rule(int start, int end, int r)
{
    if (r == 0)
    {
        return;
    }
    int mid = (start + end) / 2;
    draw_rule(start, mid, r - 1);
    mark(mid, r);
    draw_rule(mid, end, r - 1);
}

// void draw_rule_iter(int start, int end, int r)
// {
//     for(int i = 1; i <= r; i++){
//         for(int j = )
//     }
// }

void print_dash(int n)
{
    printf("\033[1d");
    for (int i = 0; i <= n; i++)
    {
        printf("*");
        printf("\033[D");
        printf("\033[B");
    }
}