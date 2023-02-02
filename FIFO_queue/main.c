#include "QUEUE.h"

#include <stdio.h>

int main()
{
    int N, x;
    scanf("%d", &N);

    QUEUEinit(N);
    while (scanf("%d", &x))
    {
        if (x == -1)
            QUEUEget();
        else
            QUEUEput(x);
        printf("----------------------------\n");
        QUEUEprint();
        printf("----------------------------\n");
    }
}