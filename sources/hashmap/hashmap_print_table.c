#include "../../includes/minishell.h"

void	hashmap_print_table(t_hashmap *table)
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
			ft_putendl_fd("----------------------------", 1);
			ft_putstr_fd("| ", 1);
			ft_putstr_fd(current->key, 1);
			ft_putstr_fd(" | = | ", 1);
			ft_putstr_fd(current->value, 1);
			ft_putendl_fd(" |", 1);
			current = tmp;
		}
		i++;
	}
	ft_putendl_fd("----------------------------", 1);
}
