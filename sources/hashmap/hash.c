#include "../../includes/hashmap.h"

unsigned long hash_function(const char *key, unsigned int size)
{
    unsigned long   hash_value;
    unsigned int    i;

    hash_value = 0;
    i = 0;
    while (i < size)
    {
        hash_value = ((hash_value << 5) + hash_value) + key[i];
        i++;
    }
    return (hash_value % size);
}

int main()
{
    const char *keys[] = {"Hel", "Cau", "Test", "AnotherTest", "HashMe"};
    unsigned int size = 1000; // Example size of the hash table
    int i = 0;
    
    while (i < 5)
    {
        printf("Hash for %s: %lu\n", keys[i], hash_function(keys[i], size));
        i++;
    }
    return 0;
}