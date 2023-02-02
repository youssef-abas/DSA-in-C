#include "STACK.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char *exp = argv[1];
    int N = strlen(exp);
    STACKinit(N);

    for (int i = 0; i < N; i++)
    {
        char c = exp[i];
        if (c >= '0' && c <= '9')
        {
            printf("%c ", c);
        }
        else if (c == '+' || c == '-' || c == '/' || c == '*')
        {
            STACKpush(c);
        }
        else if (c == ')')
        {
            printf("%c ", STACKpop());
        }
    }
    printf("\n");
}