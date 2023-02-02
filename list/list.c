#include "list.h"

#include <stdio.h>
#include <stdlib.h>

Item *list;
int size;
int end;

int expandList();

void initList(int sz)
{
    list = malloc(sizeof(Item) * sz);
    size = sz;
    end = -1;
}

int isEmpty()
{
    return end == -1;
}

int insert_at_end(Item x)
{
    if (end == size - 1)
    {
        if (expandList(size * 2) == -1)
        {
            return -1;
        }
    }

    list[++end] = x;

    return 0;
}

int insert_at_position(Item x, int pos)
{
    if (end == size - 1)
    {
        if (expandList(size * 2) == -1)
        {
            return -1;
        }
    }
    else if (pos >= size)
    {
        if (expandList(size * ((pos / size) * 2)) == -1)
        {
            return -1;
        }
    }

    for (int i = end + 1; i > pos; i--)
    {
        list[i] = list[i - 1];
    }
    list[pos] = x;
    end = (pos > end) ? pos : end + 1;

    return 0;
}

int expandList(int newSize)
{
    Item *t = list;

    if ((list = malloc(sizeof(Item) * newSize)) == NULL)
    {
        fprintf(stderr, "Memory exceeded and list cannot be expanded further");
        return -1;
    }

    for (int i = 0; i < size; i++)
    {
        list[i] = t[i];
    }
    free(t);
    size = newSize;

    return 0;
}

void print_list()
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
}