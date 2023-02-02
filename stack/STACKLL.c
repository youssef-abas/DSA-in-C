#include "STACK.h"
#include "Item.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct _node *link;
typedef struct _node
{
    Item data;
    link next;
} Node;

link top;

void STACKinit(int n)
{
    top = NULL;
}

int STACKempty()
{
    return top == NULL;
}

void STACKpush(Item x)
{
    link t = malloc(sizeof *t);
    t->data = x;

    t->next = top;
    top = t;
}

Item STACKpop()
{
    link t = top;

    top = top->next;

    Item x = t->data;
    free(t);
    return x;
}

void STACKprint()
{
    for (link x = top; x != NULL; x = x->next)
    {
        printf("%d ", x->data);
    }
}