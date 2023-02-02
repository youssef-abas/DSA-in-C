#include "QUEUE.h"

#include <stdio.h>
#include <stdlib.h>

Item *queue;
int front, end;
int size;

void QUEUEinit(int N)
{
    queue = malloc(sizeof(*queue) * N);
    front = end = -1;
    size = N;
}

int QUEUEempty()
{
    return front == end;
}

void QUEUEput(Item x)
{
    end = (end + 1) % size;
    queue[end] = x;
}

Item QUEUEget()
{
    front = (front + 1) % size;
    Item x = queue[front];

    return x;
}

void QUEUEprint()
{
    int i = front;
    while (i != end)
    {
        i = (i + 1) % size;
        printf("%d ", queue[i]);
    }
    printf("\n");
}