#include "minishell.h"

int main()
{
	const char *keys[] = {"echo", "cd", "ls", "pwd", "grep"};
	const char *values[] = {"1", "2", "3", "4", "5"};
	unsigned int size = 7; // Example size of the hash table
	unsigned int i = 0;

	// Create a new hashmap
	t_hashmap *table = create_table(size);
	printf("Hashmap created with size %u.\n", size);

	// Insert key-value pairs
	while (i < 5)
	{
		insert_in_table((char *)keys[i], (char *)values[i], table);
		printf("Inserted key `%s` with value `%s`.\n", keys[i], values[i]);
		i++;
	}

	// Table-like visualization of the hashmap
	printf("\nCurrent Hashmap with potential collisions:\n");
	printf("+-------+----------------------------+\n");
	printf("| Index | Entries                     |\n");
	printf("+-------+----------------------------+\n");
	for (unsigned int idx = 0; idx < table->size; idx++)
	{
		printf("| %5u | ", idx);
		t_entry *current = table->entries[idx];
		if (current == NULL)
		{
			printf("Empty\n");
		}
		else
		{
			while (current != NULL)
			{
				printf("(Key: %s  Value: %s) ", current->key, current->value);
				if (current->next != NULL)
					printf("-> ");
				current = current->next;
			}
			printf("\n");
		}
	}
	printf("+-------+----------------------------+\n");

	// Search for a key
	char *search_key = "ls";
	char *search_result = hashmap_search(table, search_key);
	if (search_result)
		printf("\nSearch Result: Key `%s` has value `%s`.\n", search_key, search_result);
	else
		printf("\nSearch Result: Key `%s` not found.\n", search_key);

	// Delete a key
	char *delete_key = "cd";
	hashmap_delete(table, delete_key);
	printf("\nDeleted key `%s`.\n", delete_key);

	insert_in_table("ls", "Value200", table);
	// Print the hashmap after deletion
	printf("\nHashmap after deletion:\n");
	printf("+-------+----------------------------+\n");
	printf("| Index | Entries                     |\n");
	printf("+-------+----------------------------+\n");
	for (unsigned int idx = 0; idx < table->size; idx++)
	{
		printf("| %5u | ", idx);
		t_entry *current = table->entries[idx];
		if (current == NULL)
		{
			printf("Empty\n");
		}
		else
		{
			while (current != NULL)
			{
				printf("(Key: %s  Value: %s) ", current->key, current->value);
				if (current->next != NULL)
					printf("-> ");
				current = current->next;
			}
			printf("\n");
		}
	}
	printf("+-------+----------------------------+\n");

	// Free the hashmap
	free_table(table);
	printf("\nHashmap memory freed.\n");

	return 0;
}

/* clear && cc -Wall -Wextra -Werror -o hash_test \
hashmap_create_entry.c \
hashmap_handle_collision.c \hash.c \
hashmap_create_table.c \
hashmap_insert.c \
hashmap_print_table.c \
hashmap_search.c \
hashmap_delete.c \
hashmap_free.c \
test_hashmap.c \
../../libft/libft.a \
-I../../includes && ./hash_test */
