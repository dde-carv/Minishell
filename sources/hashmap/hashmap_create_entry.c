#include "../../includes/minishell.h"

t_entry	*create_entry(char *key, char *value)
{
	t_entry *new_entry;

	new_entry = (t_entry *)ft_calloc(sizeof(t_entry), 1);
	if (!new_entry)
		return (NULL);
	new_entry->key = ft_strdup(key);
	new_entry->value = ft_strdup(value);
	return (new_entry);
}
