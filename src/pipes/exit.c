/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:53:43 by dde-carv          #+#    #+#             */
/*   Updated: 2024/11/15 14:19:58 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	free_all_cmds(char **cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
	{
		free(cmds[i]);
		i++;
	}
	free(cmds);
}

static void	ft_free_rest(t_cmd **input, char **paths)
{
	int		i;
	t_cmd	*tmp;

	while (*input)
	{
		i = 0;
		tmp = (*input);
		(*input) = (*input)->next;
		while (tmp->av[i])
		{
			free(tmp->av[i]);
			i++;
		}
		free(tmp->av);
		free(tmp->path);
		tmp->next = NULL;
		tmp->prev = NULL;
		free(tmp);
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	if (paths)
		free(paths);
}

void	exit_pipex(t_cmd *input, int error)
{
	if (data()->flag == 42)
		unlink(".temp");
	if (data()->fd_in != -1)
		close(data()->fd_in);
	if (data()->fd_out != -1)
		close(data()->fd_out);
	if (error != 0)
	{
		if (error == 1)
			ft_printf("Error:\nInvalid usage.\n");
		else if (error == 2)
		{
			input = data()->first;
			ft_free_rest(&input, data()->paths);
		}
		exit(1);
	}
	input = data()->first;
	ft_free_rest(&input, data()->paths);
	exit(0);
}
