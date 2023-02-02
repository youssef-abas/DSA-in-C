#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

link insertion_sort(link list)
{
    link sorted_list = NULL, t;

    for (link x = list; x != NULL; x = t)
    {
        t = x->next;
        if (sorted_list == NULL)
        {
            sorted_list = x;
            x->next = NULL;
        }

        link r = NULL, q = sorted_list;
        for (;;)
        {
            if (q == NULL)
            {
                r->next = x;
                x->next = NULL;
                break;
            }
            else if (x->data < q->data)
            {
                x->next = q;
                if (r == NULL)
                    sorted_list = x;
                else
                    r->next = x;
                break;
            }

            r = q;
            q = q->next;
        }
    }

    return sorted_list;
}

link generate_random_list(int N)
{
    link head = NULL, x;
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        x = malloc(sizeof *x);
        x->data = rand() % 100;
        x->next = head;
        head = x;
    }

    return head;
}

link reverse_list(link list)
{
    link r = NULL, y, t;

    for (y = list; y != NULL;)
    {
        t = y->next;
        y->next = r;
        r = y;
        y = t;
    }
    return r;
}

void print_list(link list)
{
    for (link x = list; x != NULL; x = x->next)
        printf("%d ", x->data);
    printf("\n");
}