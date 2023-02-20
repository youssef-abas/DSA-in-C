#define HT_PRIME_1 155
#define HT_PRIME_2 132

#define HT_INITIAL_BASE_SIZE 50

typedef struct
{
    char *key;
    char *value;
} ht_item;

typedef struct
{
    int size;
    int base_size;
    int count;
    ht_item **items;
} ht_hash_table;

static ht_item *ht_new_item(const char *k, const char *v);
ht_hash_table *ht_new();
static ht_hash_table *ht_new_sized(const int base_size);
static void ht_resize(ht_hash_table *ht, const int base_size);
static void ht_resize_up(ht_hash_table *ht);
static void ht_resize_down(ht_hash_table *ht);

static void ht_del_item(ht_item *i);
void ht_del_hash_table(ht_hash_table *ht);

static int ht_hash(const char *k, int a, int n);
static int ht_get_hash(const char *k, int n, int attempt);

void ht_insert(ht_hash_table *ht, const char *key, const char *value);
char *ht_search(ht_hash_table *ht, const char *key);
void ht_delete(ht_hash_table *ht, const char *key);

void ht_print(ht_hash_table *ht);