#include "../../includes/minishell.h"

void	free_t_entry(t_entry *entry)
{
	free(entry->key);
	free(entry->value);
	free(entry);
}

void	free_t_input(t_input *input)
{
	if (input->cmd)
		free(input->cmd);
	if (input->arg)
		free(input->arg);
	if (input->args)
		free_array(input->args);
	if (input->next)
		free_t_input(input->next);
	free(input);
}

void	free_table(t_hashmap *table)
{
	unsigned int	i;
	t_entry			*current;
	t_entry			*tmp;

	i = 0;
	while (i < table->size)
	{
		current = table->entries[i];
		while (current != NULL)
		{
			tmp = current->next;
			free_t_entry(current);
			current = tmp;
		}
		i++;
	}
	free(table->entries);
	free(table);
}
