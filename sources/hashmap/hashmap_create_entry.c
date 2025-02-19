/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_create_entry.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:39:42 by luiribei          #+#    #+#             */
/*   Updated: 2025/02/19 09:39:43 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
