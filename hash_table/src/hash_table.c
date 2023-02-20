#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

#include "hash_table.h"
#include "prime.h"

static ht_item HT_DELETED_ITEM = {NULL, NULL};

static ht_item *ht_new_item(const char *k, const char *v)
{
    ht_item *item = malloc(sizeof(ht_item));

    item->key = strdup(k);
    item->value = strdup(v);

    return item;
}

ht_hash_table *ht_new()
{
    return ht_new_sized(HT_INITIAL_BASE_SIZE);
}

static ht_hash_table *ht_new_sized(const int base_size)
{
    ht_hash_table *ht = malloc(sizeof(ht_hash_table));
    int size = next_prime(base_size);
    ht->base_size = base_size;
    ht->size = size;
    ht->count = 0;

    ht->items = calloc(ht->size, sizeof(ht_item *));

    return ht;
}

static void ht_resize(ht_hash_table *ht, const int base_size)
{
    if (base_size < HT_INITIAL_BASE_SIZE)
        return;

    ht_hash_table *new_ht = ht_new_sized(base_size);

    for (int i = 0; i < ht->size; i++)
    {
        ht_item *item = ht->items[i];
        if (item != NULL && item != &HT_DELETED_ITEM)
        {
            ht_insert(new_ht, item->key, item->value);
        }
    }

    ht->base_size = base_size;

    int temp = ht->size;
    ht->size = new_ht->size;
    new_ht->size = temp;

    temp = ht->count;
    ht->count = new_ht->count;
    new_ht->count = temp;

    ht_item **l = ht->items;
    ht->items = new_ht->items;
    new_ht->items = l;

    ht_del_hash_table(new_ht);
}

static void ht_resize_up(ht_hash_table *ht)
{
    int new_size = ht->base_size * 2;
    ht_resize(ht, new_size);
}
static void ht_resize_down(ht_hash_table *ht)
{
    int new_size = ht->base_size / 2;
    ht_resize(ht, new_size);
}

static void ht_del_item(ht_item *i)
{
    free(i->key);
    free(i->value);

    free(i);
}

void ht_del_hash_table(ht_hash_table *ht)
{
    for (int i = 0; i < ht->size; i++)
    {
        ht_item *item = ht->items[i];
        if (item != NULL)
            ht_del_item(item);
    }

    free(ht->items);
    free(ht);
}

static int ht_hash(const char *k, const int a, const int n)
{
    long h = 0;
    int len = strlen(k);

    for (int i = 0; i < len; i++)
    {
        h += (long)pow(a, len - (i + 1)) * k[i];
    }
    h = h % n;

    return (int)h;
}

static int ht_get_hash(const char *k, int n, int attempt)
{
    int hash_a = ht_hash(k, HT_PRIME_1, n);
    int hash_b = ht_hash(k, HT_PRIME_2, n);

    return (hash_a + attempt * (hash_b + 1)) % n;
}

void ht_insert(ht_hash_table *ht, const char *key, const char *value)
{
    const int load = 100 * ht->count / ht->size;
    if (load > 70)
    {
        ht_resize_up(ht);
    }
    ht_item *item = ht_new_item(key, value);
    int h = ht_get_hash(key, ht->size, 0);
    ht_item *curr_item = ht->items[h];

    int i = 1;
    while (curr_item != NULL && curr_item != &HT_DELETED_ITEM)
    {
        if (strcmp(curr_item->key, key) == 0)
        {
            ht->items[h]->value = strdup(value);
            free(item);
            return;
        }
        h = ht_get_hash(key, ht->size, i);
        curr_item = ht->items[h];
        i++;
    }
    ht->items[h] = item;
    ht->count++;
}

char *ht_search(ht_hash_table *ht, const char *key)
{
    int index = ht_get_hash(key, ht->size, 0);
    ht_item *curr_item = ht->items[index];

    int i = 1;
    while (curr_item != NULL)
    {
        if (curr_item != &HT_DELETED_ITEM)
            if (strcmp(curr_item->key, key) == 0)
                return curr_item->value;
        index = ht_get_hash(key, ht->size, i);
        curr_item = ht->items[index];
        i++;
    }

    return NULL;
}

void ht_delete(ht_hash_table *ht, const char *key)
{
    const int load = 100 * ht->count / ht->size;
    if (load < 10)
    {
        ht_resize_down(ht);
    }
    int index = ht_get_hash(key, ht->size, 0);
    ht_item *curr_item = ht->items[index];

    int i = 1;
    while (curr_item != NULL)
    {
        if (curr_item != &HT_DELETED_ITEM)
            if (strcmp(curr_item->key, key) == 0)
            {
                ht_del_item(curr_item);
                ht->items[index] = &HT_DELETED_ITEM;
            }
        index = ht_get_hash(key, ht->size, i);
        curr_item = ht->items[index];
        i++;
    }

    ht->count--;
}

void ht_print(ht_hash_table *ht)
{
    for (int i = 0; i < ht->size; i++)
    {
        ht_item *item = ht->items[i];
        if (item != NULL && item != &HT_DELETED_ITEM)
        {
            printf("%s ------> %s\n", item->key, item->value);
        }
    }
}