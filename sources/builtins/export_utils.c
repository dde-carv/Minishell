/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:18:41 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/08 10:18:42 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	matrix_len(char **matrix)
{
	int	i;

	i = 0;
	if (*matrix)
	{
		while (matrix[i + 1])
			i++;
	}
	return (i);
}

static int	print_export(int fd)
{
	char	**export;

	export = hashmap_quotes_array_and_non_value_vars();
	quick_sort(export, 0, matrix_len(export));
	ft_strjoin_to_array("declare -x ", export);
	print_array_fd(export, fd);
	free_array((void **)export);
	return (0);
}

int	ft_export(char **args, int fd)
{
	minis()->error_status = 0;
	if (args[0])
		return (add_var(args, 0));
	else
		return (print_export(fd));
}
