#include "../../includes/minishell.h"

void	insert_in_table(char *key, char *value, t_hashmap *table)
{
	unsigned long	index;
	t_entry			*new_entry;
	t_entry			*current;

	index = hash_function(key, table->size);
	new_entry = create_entry(key, value);
	current = table->entries[index];
	if (current == NULL)
	{
		table->entries[index] = new_entry;
		table->count += 1;
	}
	else
	{
		if (ft_strncmp(current->key, key, ft_strlen(key) + 1) == 0)
		{
			free (current->value);
			current->value = ft_strdup(value);
			free_t_entry(new_entry);
		}
		else
			handle_collision(table, index, new_entry);
	}
}
