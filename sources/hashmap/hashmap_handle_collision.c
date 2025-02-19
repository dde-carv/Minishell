/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_handle_collision.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:39:56 by luiribei          #+#    #+#             */
/*   Updated: 2025/02/19 09:39:57 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
