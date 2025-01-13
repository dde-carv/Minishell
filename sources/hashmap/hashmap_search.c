#include "../../includes/minishell.h"

char	*hashmap_search(t_hashmap *table, char *key)
{
	unsigned long	index;
	t_entry			*current;

	index = hash_function(key, table->size);
	current = table->entry[index];
	while (current != NULL)
	{
		if (ft_strncmp(current->key, key, ft_strlen(key) + 1) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}
