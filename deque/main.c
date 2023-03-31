#include <stdio.h>

#include "deque.h"

int main()
{
    init_deque();

    addFront(5);
    printDeque();
    addBack(6);
    addBack(71);
    addFront(-14);

    printDeque();

    removeBack();
    printDeque();

    removeFront();
    printDeque();

    removeBack();
    printDeque();

    removeBack();
    printDeque();

    removeFront();
}