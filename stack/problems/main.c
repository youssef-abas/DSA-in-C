#include "STACK.h"

#include <stdio.h>
#include <string.h>

int main()
{
    char sen[255], c;
    fgets(sen, 255, stdin);

    int n = strlen(sen);
    STACKinit(n);

    int i = 0;
    while ((c = sen[i++]) != '\n')
    {
        if (c != '*')
            STACKpush(c);
        else
            printf("%c ", STACKpop());
    }
    printf("\n");
}