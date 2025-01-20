#include "../../includes/minishell.h"

char	*hashmap_search(t_hashmap *table, char *key)
{
	unsigned long	index;
	t_entry			*current;

	index = hash_function(key, table->size);
	current = table->entries[index];
	while (current != NULL)
	{
		if (ft_strncmp(current->key, key, ft_strlen(key) + 1) == 0)
			return (current->value);
		current = current->next;
	}
	return (""); //? Not what we want but need this fix for now ("cd -" gets a conditional jump if OLDPWD is not set)
}
