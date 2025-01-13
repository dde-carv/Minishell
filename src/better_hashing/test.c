#include "hashtable.h"

#define MAX_LINE 10

unsigned long my_hash_function(const char *entry, size_t len)
{
    unsigned long hash_value;
    size_t i;

    hash_value = 0;
    i = 0;

    while (i < len)
    {
        hash_value += entry[i];
        hash_value = (hash_value * entry[i]);
        i++;
    }
    return (hash_value);
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("usage: %s <wordlist filename> <num guesses>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *filename = argv[1];
    //uint32_t num_guesses = atol(argv[2]);

    const int tablesize = 10;
    hash_table *table = hash_table_create(my_hash_function, tablesize);

    FILE *fp = fopen(filename, "r");
    char buffer[MAX_LINE];
    size_t numwords = 0;

    while (!feof(fp) && fgets(buffer, MAX_LINE, fp) != NULL)
    {
        buffer[strcspn(buffer, "\n\r")] = 0;
        char *newentry = malloc(strlen(buffer) + 1);
        strcpy(newentry, buffer);
        hash_table_insert(table, newentry, newentry);
        numwords++;
    }
    fclose(fp);
    printf("Loaded %zu words into the table.\n", numwords);

    hash_table_print(table);

    // lookup for a key entry that we know is in the table
    const char *search_key = "cd";
    printf("Looking for %s...\n", search_key);
    void *tmp = hash_table_lookup(table, search_key);
    if (tmp == NULL)
        printf("Not found!\n");
    else
        printf("Found! %s.\n", (char *)tmp);

    //hash_table_destroy(table);
    return (EXIT_SUCCESS);
}