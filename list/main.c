#include "list.h"

int main()
{
    initList(5);

    insert_at_end(23);
    insert_at_position(-5, 2);
    insert_at_end(4);
    insert_at_end(2);
    insert_at_position(-1, 0);
    insert_at_end(-3);
    insert_at_end(24);
    insert_at_position(23, 7);
    insert_at_position(-1, 250);
    insert_at_end(5);

    print_list();
}