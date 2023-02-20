#include <stdio.h>

#include "hash_table.h"

int main()
{
    ht_hash_table *ht = ht_new();

    ht_insert(ht, "Cat", "Feline");
    ht_insert(ht, "Dog", "Canine");
    ht_insert(ht, "Dog", "What da");

    // printf("%s\n", ht_search(ht, "Dog"));
    ht_print(ht);

    ht_del_hash_table(ht);
}