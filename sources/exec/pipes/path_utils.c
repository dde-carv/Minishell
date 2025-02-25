/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:54:40 by dde-carv          #+#    #+#             */
/*   Updated: 2025/02/25 14:09:15 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* static t_input	*ft_lastcmd(t_input *input)
{
	if (!input)
		return (NULL);
	while (input->next != NULL)
		input = input->next;
	return (input);
}

void	ft_addcmd(t_input **input, t_input *new)
{
	t_input	*last;

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

t_input	*ft_newcmd(char *cmd, char *path, int is_last)
{
	t_input	*new;

	new = (t_input *)malloc(sizeof(t_input));
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
} */

char	**ft_get_path(char **envp)
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

char	*ft_check_path(char *cmd, char **paths)
{
	int		i;
	char	*path_cmd;

	path_cmd = NULL;
	if ((cmd[0] == '/') || (!ft_strncmp(cmd, "./", 2)))
		return(full_path(cmd, paths));
	i = -1;
	while (paths[++i])
	{
		path_cmd = ft_strjoin_var(3, paths[i], "/", cmd);
		if (access(path_cmd, F_OK | X_OK) == 0)
			return (path_cmd);
		free(path_cmd);
	}
	return (NULL);
}
