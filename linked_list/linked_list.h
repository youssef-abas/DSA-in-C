#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdlib.h>
#include <stdio.h>

typedef int item;
typedef struct node *link;

struct node
{
    item data;
    link next;
};

typedef link Node;

link initNodes(int);
link newNode(item);
void freeNode(link);
void insertNext(link, link);
link deleteNext(link);
link Next(link);
int Data(link);

void displayList(link);

#endif