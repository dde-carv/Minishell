/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:20:45 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/08 10:20:46 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_pointer(void *str)
{
	if (!str)
		return ;
	free(str);
	str = NULL;
}

void	free_array(void **array)
{
	int	i;

	if (!array)
		return ;
	i = -1;
	while (array[++i])
		free_pointer(array[i]);
	free(array);
	array = NULL;
}
