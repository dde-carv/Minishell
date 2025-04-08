/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:18:01 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/08 10:18:02 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	array_len(char **array)
{
	int	i;

	i = 0;
	if (*array)
	{
		while (array[i])
			i++;
	}
	return (i);
}

void	ft_strjoin_to_array(char *str, char **array)
{
	int		i;
	char	*tmp;

	i = 0;
	while (array[i])
	{
		tmp = ft_strjoin(str, array[i]);
		free(array[i]);
		array[i] = tmp;
		i++;
	}
}

void	print_array_fd(char **array, int fd)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_putendl_fd(array[i], fd);
		i++;
	}
}

char	**split_into2(char *arg, char c)
{
	char	**splited;
	char	*c_p;

	splited = (char **)malloc(3 * sizeof(char *));
	c_p = ft_strchr(arg, c);
	splited[0] = ft_substr(arg, 0, (c_p - arg));
	if (!*(c_p + 1))
		splited[1] = ft_strdup("");
	else
		splited[1] = ft_substr((c_p + 1), 0, (ft_strlen(c_p)));
	splited[2] = NULL;
	return (splited);
}
