#include "../../includes/minishell.h"

void	free_entry(t_entry *entry)
{
	free(entry->key);
	free(entry->value);
	free(entry);
}

void	free_table(t_hashmap *table)
{
	unsigned int	i;
	t_entry			*current;
	t_entry			*tmp;

	i = 0;
	while (i < table->size)
	{
		current = table->entry[i];
		while (current != NULL)
		{
			tmp = current->next;
			free_entry(current);
			current = tmp;
		}
		i++;
	}
	free(table->entry);
	free(table);
}
