/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:19:54 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/08 10:19:55 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

static char	*full_path(char *cmd)
{
	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	return (ft_strdup(""));
}

char	*ft_check_path(char *cmd, char **paths)
{
	int		i;
	char	*path_cmd;

	path_cmd = NULL;
	if ((cmd[0] == '/') || (!ft_strncmp(cmd, "./", 2)))
		return (full_path(cmd));
	i = -1;
	while (paths[++i])
	{
		path_cmd = ft_strjoin_var(3, paths[i], "/", cmd);
		if (access(path_cmd, F_OK | X_OK) == 0)
			return (path_cmd);
		free(path_cmd);
	}
	return (ft_strdup(""));
}

static char	*get_cmd(t_input *n, int i)
{
	t_input	*tmp;
	int		j;

	tmp = n;
	j = -1;
	while (++j < i && tmp)
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	return (tmp->cmd);
}

void	get_cmd_path(t_pipe *pipex, t_input *input)
{
	int	i;
	int	n;

	i = 0;
	n = ft_input_lstsize(&input) - 1;
	while (i < n)
	{
		pipex->cmd_paths[i] = ft_check_path(get_cmd(input, i),
				pipex->env_paths);
		i++;
	}
	pipex->cmd_paths[i] = NULL;
	pipex->last_path = ft_check_path(get_cmd(input, n), pipex->env_paths);
}

char	**ft_get_env_paths(void)
{
	char	**paths;

	paths = NULL;
	if (hashmap_search(minis()->env, "PATH"))
		paths = ft_split(hashmap_search(minis()->env, "PATH"), ':');
	else
		paths = ft_split("", ' ');
	return (paths);
}
