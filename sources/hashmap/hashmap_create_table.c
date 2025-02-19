/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_create_table.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:39:45 by luiribei          #+#    #+#             */
/*   Updated: 2025/02/19 09:39:46 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_hashmap	*create_table(unsigned int size)
{
	t_hashmap		*new_table;
	unsigned int	i;

	i = 0;
	new_table = (t_hashmap *)ft_calloc(sizeof(t_hashmap), 1);
	if (!new_table)
		return (NULL);
	new_table->count = 0;
	new_table->size = size;
	new_table->entries = (t_entry **)ft_calloc(sizeof(t_hashmap), size);
	if (!new_table->entries)
	{
		free(new_table);
		return (NULL);
	}
	while (i < size)
		new_table->entries[i++] = NULL;
	return (new_table);
}
