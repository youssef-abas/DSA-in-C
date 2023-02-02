#include "QUEUE.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;
struct node
{
    Item data;
    link next;
};
static struct node front;
static struct node end;

void QUEUEinit(int N)
{
    front.next = NULL;
    end.next = NULL;
}

int QUEUEempty()
{
    return front.next == NULL;
}

void QUEUEput(Item x)
{
    link t = malloc(sizeof *t);
    t->data = x;
    t->next = NULL;

    if (front.next == NULL)
        front.next = t;
    else
        end.next->next = t;

    end.next = t;
}

Item QUEUEget()
{
    link t = front.next;
    Item x = t->data;

    front.next = t->next;
    if (end.next == t)
    {
        end.next = NULL;
    }

    free(t);
    return x;
}

void QUEUEprint()
{
    link x = front.next;

    while (x != NULL)
    {
        printf("%d ", x->data);
        x = x->next;
    }
    printf("\n");
}