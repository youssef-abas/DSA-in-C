#include <stdio.h>
#include <stdlib.h>

#include "deque.h"

typedef struct _node
{
    Item value;
    struct _node *next;
    struct _node *prev;
} Node;

Node *head;
Node *tail;

void init_deque()
{
    head = tail = NULL;
}

void addFront(Item elem)
{
    Node *newNode = malloc(sizeof *newNode);
    if (newNode == NULL)
    {
        fprintf(stderr, "Malloc ran out of space.\n");
        exit(1);
    }

    newNode->value = elem;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;

        head->next = newNode;
        head->prev = newNode;

        return;
    }

    newNode->next = head;
    newNode->prev = tail;

    head->prev = newNode;
    tail->next = newNode;

    head = newNode;
}

void addBack(Item elem)
{
    Node *newNode = malloc(sizeof *newNode);
    if (newNode == NULL)
    {
        fprintf(stderr, "Malloc ran out of space.\n");
        exit(1);
    }

    newNode->value = elem;

    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;

        return;
    }

    newNode->prev = tail;
    newNode->next = head;

    tail->next = newNode;
    head->prev = newNode;

    tail = newNode;
}

Item peekFront()
{
    if (head != NULL)
    {
        fprintf(stderr, "Tried to peek at empty list.\n");
        exit(1);
    }

    return head->value;
}

Item peekBack()
{
    if (tail == NULL)
    {
        fprintf(stderr, "Tried to peek at empty list.\n");
        exit(1);
    }

    return tail->value;
}

Item removeFront()
{
    if (head == NULL)
    {
        fprintf(stderr, "Tried to remove from empty list.\n");
        exit(1);
    }

    if (head == tail)
    {
        Item val = head->value;

        free(head);
        head = tail = NULL;
        return val;
    }

    Node *temp = head;

    tail->next = head->next;
    head->next->prev = tail;

    head = head->next;
    free(temp);
}

Item removeBack()
{
    if (tail == NULL)
    {
        fprintf(stderr, "Tried to remove from empty list.\n");
        exit(1);
    }

    if (head == tail)
    {
        Item val = head->value;

        free(head);
        head = tail = NULL;
        return val;
    }

    Node *temp = tail;

    tail = tail->prev;
    tail->next = head;

    head->prev = tail;

    free(temp);
}

void printDeque()
{
    if (head == NULL)
    {
        printf("{}\n");
        return;
    }
    Node *curr = head;

    printf("{");
    while (curr->next != head)
    {
        printf("%d ", curr->value);
        curr = curr->next;
    }

    printf("%d}\n", curr->value);
}