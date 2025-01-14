#include "../../includes/minishell.h"

t_hashmap	*create_table(unsigned int size)
{
	t_hashmap		*new_table;
	unsigned int	i;

	i = 0;
	new_table = (t_hashmap *)ft_calloc(sizeof(t_hashmap), 1);
	new_table->size = size;
	new_table->count = 0;
	new_table->entries = (t_entry **)ft_calloc(sizeof(t_hashmap), size);
	while (i < size)
	{
		new_table->entries[i] = NULL;
		i++;
	}
	return (new_table);
}
