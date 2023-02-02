#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int N = atoi(argv[1]),
        M = atoi(argv[2]);
    int i = 0;

    link head = malloc(sizeof *head);

    head->data = 1;
    head->next = head;
    link x = head;
    link t;

    while (i < N - 1)
    {
        t = malloc(sizeof *t);
        x->next = t;
        t->next = head;
        t->data = i + 2;
        x = t;
        i++;
    }

    i = 0;
    link iter = head;
    while (i < N)
    {
        printf("%d - ", iter->data);
        iter = iter->next;
        i++;
    }
    printf("\n");

    i = 0;
    while (i < N - 1)
    {
        for (int i = 0; i < M - 1; i++, x = x->next)
            ;
        printf("%d - ", x->next->data);
        t = x->next;
        x->next = t->next;
        free(t);
        i++;
    }
    printf("\n");
    printf("%d is the winner of the election!\n", x->data);
}