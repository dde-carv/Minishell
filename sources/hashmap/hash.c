#include "../../includes/minishell.h"

unsigned long	hash_function(const char *key, unsigned int size)
{
	unsigned long	hash_value;
	unsigned int	i;

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
	const char *keys[] = {"echo", "cd", "ls", "pwd", "grep"};
	const char *values[] = {"Value1", "Value2", "Value3", "Value4", "Value5"};
	unsigned int size = 1000; // Example size of the hash table
	int i = 0;
	t_hashmap *table = create_table(size);

	while (i < 5)
	{
		unsigned long hash = hash_function(keys[i], size);
		t_entry *entry = create_entry((char *)keys[i], (char *)values[i]);
		table->entry[hash] = entry;
		printf("Inserted key %s:\t %s at index %lu\n", keys[i], values[i], hash);
		i++;
	}
	return 0;
}

// clear && cc -Wall -Wextra -Werror -o hash_test hash.c create_entry.c create_table.c ../../libft/libft.a && ./hash_test && rm hash_test
