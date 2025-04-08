/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:19:11 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/08 10:19:12 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	partition(char **array, int left, int right)
{
	int		i;
	int		j;
	char	*pivot;
	char	*temp;

	pivot = array[left];
	i = left;
	j = left + 1;
	while (j <= right)
	{
		if (ft_strcmp(pivot, array[j]) > 0)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		j++;
	}
	temp = pivot;
	array[left] = array[i];
	array[i] = temp;
	return (i);
}

void	quick_sort(char **array, int left, int right)
{
	unsigned int	pivot_i;

	if (left < right)
	{
		pivot_i = partition(array, left, right);
		quick_sort(array, left, pivot_i - 1);
		quick_sort(array, pivot_i + 1, right);
	}
}
