#include "STACK.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char exp[255];
    fgets(exp, 255, stdin);

    int N = strlen(exp) - 1;
    char c;
    int i = 0;
    int num = 0;

    STACKinit(N);

    while (i < N)
    {
        c = exp[i];
        if (c > '9' || c < '0')
        {
            switch (c)
            {
            case '*':
                STACKpush(STACKpop() * STACKpop());
                i++;
                break;
            case '+':
                STACKpush(STACKpop() + STACKpop());
                i++;
                break;
            default:
                i++;
                continue;
            }
        }
        else
        {
            while (c >= '0' && c <= '9')
            {
                num = num * 10 + (c - '0');
                c = exp[++i];
            }
            STACKpush(num);
            num = 0;
        }
    }

    printf("Result = %d\n", STACKpop());
}