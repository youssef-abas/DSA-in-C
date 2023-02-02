#ifndef LINKED_LIST
#define LINKED_LIST

typedef int Item;

typedef struct node *link;

struct node
{
    Item data;
    link next;
};

link insertion_sort(link);
link generate_random_list(int N);
link reverse_list(link);
void print_list(link);

#endif