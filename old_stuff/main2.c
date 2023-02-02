#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int N = atoi(argv[1]);
    link head = generate_random_list(N);

    print_list(head);

    head = reverse_list(head);
    print_list(head);
    
    print_list(insertion_sort(head));
}