#include "minishell.h"

void	handle_collision(t_hashmap *table,
		unsigned long index, t_entry *new_entry)
{
	t_entry	*current;

	current = table->entries[index];
	while (current->next != NULL)
		current = current->next;
	current->next = new_entry;
	current->next->next = NULL;
	table->count += 1;
}
