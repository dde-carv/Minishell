/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_handle_collision.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:20:37 by luiribei          #+#    #+#             */
/*   Updated: 2025/04/08 10:21:29 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
