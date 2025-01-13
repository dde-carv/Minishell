/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:54:40 by dde-carv          #+#    #+#             */
/*   Updated: 2024/11/16 22:37:36 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

static t_cmd	*ft_lastcmd(t_cmd *input)
{
	if (!input)
		return (NULL);
	while (input->next != NULL)
		input = input->next;
	return (input);
}

void	ft_addcmd(t_cmd **input, t_cmd *new)
{
	t_cmd	*last;

	if (!input || !new)
		return ;
	if (!*input)
		*input = new;
	else
	{
		last = ft_lastcmd(*input);
		last->next = new;
		new->prev = last;
	}
}

t_cmd	*ft_newcmd(char *cmd, char *path, int is_last)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->av = ft_split(cmd, ' ');
	new->cmd = new->av[0];
	if (!is_last)
	{
		if (pipe(new->fd) == -1)
		{
			ft_printf("Error: Pipe creation failed\n");
			free(new);
			return (NULL);
		}
	}
	else
	{
		new->fd[0] = -1;
		new->fd[1] = -1;
	}
	new->path = path;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

char	*check_path(char *cmd, char **paths)
{
	int		i;
	char	*main_cmd;
	char	*path;
	char	*path_cmd;
	char	**all_cmds;

	all_cmds = ft_split(cmd, ' ');
	main_cmd = ft_strdup(all_cmds[0]);
	free_all_cmds(all_cmds);
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		path_cmd = ft_strjoin(path, main_cmd);
		free(path);
		if (access(path_cmd, F_OK | X_OK) == 0)
		{
			free(main_cmd);
			return (path_cmd);
		}
		free(path_cmd);
		i++;
	}
	free(main_cmd);
	return (NULL);
}

char	**get_path(char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	paths = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = ft_split(envp[i] + 5, ':');
			return (paths);
		}
		i++;
	}
	exit_pipex(NULL, 1);
	return (paths);
}
