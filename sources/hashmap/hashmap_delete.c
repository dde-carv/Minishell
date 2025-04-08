/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:20:27 by luiribei          #+#    #+#             */
/*   Updated: 2025/04/08 10:21:26 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	find_and_delete_node(t_hashmap *table,
			t_entry *current, char *key)
{
	t_entry	*tmp;

	while (current->next != NULL)
	{
		if (ft_strncmp(current->next->key, key, ft_strlen(key) + 1) == 0)
		{
			tmp = current->next;
			current->next = current->next->next;
			free_t_entry(tmp);
			table->count -= 1;
			return ;
		}
		current = current->next;
	}
}

static void	free_current_head(t_hashmap *table, t_entry *current,
			unsigned long int index)
{
	table->entries[index] = current->next;
	free_t_entry(current);
	table->count -= 1;
}

static void	set_head_to_null(t_hashmap *table, t_entry *current,
			unsigned long int index)
{
	free_t_entry(current);
	table->entries[index] = NULL;
	table->count -= 1;
}

void	hashmap_delete(t_hashmap *table, char *key)
{
	unsigned long int	index;
	t_entry				*current;

	index = hash_function(key, table->size);
	current = table->entries[index];
	if (current == NULL)
		return ;
	else if (current->next == NULL
		&& ft_strncmp(current->key, key, ft_strlen(key) + 1) == 0)
	{
		set_head_to_null(table, current, index);
		return ;
	}
	else if (current->next != NULL
		&& ft_strncmp(current->key, key, ft_strlen(key) + 1) == 0)
	{
		free_current_head(table, current, index);
		return ;
	}
	else
		find_and_delete_node(table, current, key);
}
