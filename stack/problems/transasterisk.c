#include "STACK.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s1[255], s2[255];

    scanf("%s", s1);
    scanf("%s", s2);

    int n1 = strlen(s1);
    int n2 = strlen(s2);

    if (n1 != n2)
    {
        fprintf(stderr, "Both strings must be of same length!");
        exit(1);
    }

    STACKinit(n1);

    int i = 0;
    int j = 0;
    char c;

    while (j < n2)
    {
        if (i < n1)
        {
            if (s1[i] == s2[j])
            {
                j++;
            }
            else
            {
                STACKpush(s1[i]);
            }
        }
        else
        {
            if ((c = STACKpop()) != s2[j])
            {
                break;
            }
            else
            {
                j++;
            }
        }
        i++;
    }

    if (j != n2)
    {
        printf("No sequence exists");
    }
    else
    {
        printf("Such a sequence exists");
    }

    printf("\n");
}