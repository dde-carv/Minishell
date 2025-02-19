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
	return (NULL);
}

t_entry	*hash_action(t_hashmap *table, t_entry entry, t_action action)
{
	//entry = (t_entry){.key = ft_strdup(entry.key), .value = ft_strdup(entry.value), .next = NULL};
	char	*value = NULL;

	if (!entry.key || (action != FIND && action != ENTER) || !table)
		return (NULL);
	if (action == ENTER)
	{
		insert_in_table(entry.key, entry.value, table);
		return (create_entry(entry.key, entry.value));
	}
	if (action == FIND)
	{
		value = hashmap_search(table, entry.key);
		if (value)
			return (create_entry(entry.key, value));
	}
	return (NULL);
}

/* t_entry	*hash_action(t_hashmap *table, t_entry entry, t_action action)
{
	if (!entry.key || (action != FIND && action != ENTER) || !table)
		return (NULL);
	if (action == ENTER)
		return (insert_in_table(entry.key, entry.value, table));
	if (action == FIND)
		return (hash_search(table->entries[hash(entry.key, table->size)], entry));
	return (NULL);
} */
