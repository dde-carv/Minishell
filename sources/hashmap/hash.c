/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:20:20 by luiribei          #+#    #+#             */
/*   Updated: 2025/04/08 10:23:07 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned long	hash_function(const char *key, size_t size)
{
	unsigned long	hash_value;
	unsigned int	i;

	hash_value = 0;
	i = 0;
	while (i < size && key[i])
	{
		hash_value = ((hash_value << 5) + hash_value) + key[i];
		i++;
	}
	return (hash_value % size);
}
