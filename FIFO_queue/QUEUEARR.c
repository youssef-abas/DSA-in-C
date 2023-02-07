#include "QUEUE.h"

#include <stdio.h>
#include <stdlib.h>

Item *queue;
int front, end;
int size;

void QUEUEinit(int N)
{
    queue = malloc(sizeof(*queue) * (N + 1));
    size = N + 1;
    front = size;
    end = 0;
}

int QUEUEempty()
{
    return front % size == end;
}

void QUEUEput(Item x)
{
    if ((end + 1) % size == front % size)
    {
        QUEUEerror();
        return;
    }
    queue[end++] = x;
    end = end % size;
}

Item QUEUEget()
{
    if (QUEUEempty())
    {
        QUEUEerror();
        return NULL;
    }
    front = front % size;
    Item x = queue[front];
    queue[front] = 0;
    front++;

    return x;
}

int QUEUEerror()
{
    fprintf(stderr, "Either list is full or empty!");
    return -1;
}

void QUEUEprint()
{
    int i = front % size;
    while (i != end)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % size;
    }
    printf("\n");
}