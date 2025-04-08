/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:18:19 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/08 10:18:20 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	verify_new(char **args, int *i)
{
	int		j;
	int		new_flag;

	j = 0;
	new_flag = 1;
	while (args[*i] && !ft_strncmp(args[*i], "-n", 2))
	{
		j = 1;
		while (args[*i][j] && args[*i][j] == 'n')
			j++;
		if (!args[*i][j])
			new_flag = 0;
		else
			return (new_flag);
		(*i)++;
	}
	return (new_flag);
}

void	ft_echo(char **args, int fd)
{
	int	i;
	int	new_flag;

	i = 0;
	new_flag = verify_new(args, &i);
	while (args && args[i])
	{
		if (args[i + 1])
		{
			ft_putstr_fd(args[i], fd);
			ft_putstr_fd(" ", fd);
		}
		else
			ft_putstr_fd(args[i], fd);
		i++;
	}
	if (new_flag)
		ft_putstr_fd("\n", fd);
	minis()->error_status = 0;
}
