#include "../../includes/minishell.h"

// Mock implementation of minis() and related structures for testing
t_global *minis(void)
{
	static t_global data;
	static t_minishell ms;
	static t_hashmap env;
	static t_hashmap sesion_vars;

	if (!data.ms)
	{
		data.ms = &ms;
		data.input = NULL;
		data.env = &env;
		data.sesion_vars = &sesion_vars;
	}
	return &data;
}

int main()
{
	minis()->ms->line = "infile ls | pwd | whoami | date | hostname | uname -a |";
	minis()->table = create_table(100);
	parse_input();
	
	t_input *current_input = minis()->input;
	if (current_input)
	{
		ft_printf("Parsed Commands:\n");
		while (current_input)
		{
			ft_printf("Command: %s, Argument: %s\n", current_input->cmd, current_input->arg);
			current_input = current_input->next;
		}
	}
	else
		printf("Input line is empty.\n");

	/* // Additional assertions can be added here to verify the hash table entries
	// For example:
	t_entry *entry = hash_action(minis()->table, (t_entry){ "echo", "Hello World", NULL }, ENTER);
	if (entry)
		printf("Hash Entry - Command: %s, Argument: %s\n", entry->key, entry->value);
	else
		printf("Hash entry creation failed.\n");
	
	// Print all hash entries
	printf("All Hash Entries:\n");
	for (unsigned int i = 0; i < minis()->table->size; i++)
	{
		t_entry *current = minis()->table->entries[i];
		while (current)
		{
			printf("Key: %s, Value: %s\n", current->key, current->value);
			current = current->next;
		}
	} */
	return 0;
}

/* clear && cc -Wall -Wextra -Werror -o test_parsing parsing.c \
test_parsing.c \
../hashmap/hashmap_create_table.c \
../hashmap/hashmap_handle_collision.c \
../hashmap/hashmap_free.c \
../hashmap/hashmap_search.c \
../hashmap/hashmap_create_entry.c \
../hashmap/hash.c \
../hashmap/hashmap_insert.c \
../../libft/libft.a \
-I../../includes && ./test_parsing && rm test_parsing*/
