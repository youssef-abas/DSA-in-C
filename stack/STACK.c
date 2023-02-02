#include "STACK.h"

#include <stdio.h>
#include <stdlib.h>

Item *stack;
int top;

void STACKinit(int n)
{
    stack = malloc(sizeof(*stack) * n);
    top = -1;
}

int STACKempty()
{
    return top == -1;
}

void STACKpush(Item x)
{
    stack[++top] = x;
}

Item STACKpop()
{
    return stack[top--];
}

void STACKprint()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}