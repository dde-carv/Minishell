
#include "../../../includes/pipex.h"

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

static char	*full_path(char *cmd)
{
	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	//error_mess(cmd, NO_FILE_OR_DIR, 127);
	return (ft_strdup(""));
}

char	*ft_check_path(char *cmd, char **paths)
{
	int		i;
	char	*path_cmd;

	path_cmd = NULL;
	if ((cmd[0] == '/') || (!ft_strncmp(cmd, "./", 2)))
		return(full_path(cmd));
	i = -1;
	while (paths[++i])
	{
		path_cmd = ft_strjoin_var(3, paths[i], "/", cmd);
		if (access(path_cmd, F_OK | X_OK) == 0)
			return (path_cmd);
		free(path_cmd);
	}
	//error_mess(cmd, NOT_FOUND, 127);
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
		pipex->cmd_paths[i] = ft_check_path(get_cmd(input, i), pipex->env_paths);
		i++;
	}
	pipex->cmd_paths[i] = NULL;
	pipex->last_path = ft_check_path(get_cmd(input, n), pipex->env_paths);

/* 	printf("----> cmd array <----\n");
	print_array_fd(pipex->cmd_paths, 1);
	printf("----> last  cmd <----\n%s\n", pipex->last_path); */

}

char	**ft_get_env_paths()
{
	char	**paths;

	paths = NULL;
	if (hashmap_search(minis()->env, "PATH"))
		paths = ft_split(hashmap_search(minis()->env, "PATH"), ':');
	return (paths);
}
