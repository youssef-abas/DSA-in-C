#include "linked_list.h"

link newNode(item data)
{
    link t = malloc(sizeof(*t));

    t->data = data;
    t->next = NULL;

    return t;
}

link initNodes(int n)
{
    link s = malloc(sizeof *s), t;
    link list = s;
    list->data = 0;

    for (int i = 1; i < n; i++)
    {
        t = newNode(i);
        s->next = t;
        s = t;
    }

    return list;
}

void displayList(link list)
{
    link x = list;
    while (x != NULL)
    {
        printf("%d ", x->data);
        x = x->next;
    }

    printf("\n");
}