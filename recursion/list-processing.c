#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;
struct node
{
    int data;
    link next;
};

void print_list(link x);
int count(link x);
void traverse(link h, void (*visit)(link));
void traverseR(link h, void (*visit)(link));
link delete(link x, int v);

int main()
{
    link h = malloc(sizeof(struct node));
    h->data = 5;

    h->next = malloc(sizeof(struct node));
    h->next->data = 12;

    h->next->next = malloc(sizeof(struct node));
    h->next->next->data = 11;

    print_list(h);
    h = delete (h, 11);

    print_list(h);
}

void print_list(link x)
{
    for (link t = x; t != NULL; t = t->next)
    {
        printf("%d ", t->data);
    }
    printf("\n");
}

int count(link x)
{
    if (x == NULL)
    {
        return 0;
    }

    return 1 + count(x->next);
}

void traverse(link h, void (*visit)(link))
{
    if (h == NULL)
        return;

    (*visit)(h);
    traverse(h->next, visit);
}

void traverseR(link h, void (*visit)(link))
{
    if (h == NULL)
        return;

    traverseR(h->next, visit);
    (*visit)(h);
}

link delete(link x, int v)
{
    if (x->data == v)
    {
        link t = x->next;
        free(x);

        return t;
    }

    x->next = delete (x->next, v);
    return x;
}