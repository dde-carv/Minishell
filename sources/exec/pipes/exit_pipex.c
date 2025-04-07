
#include "../../../includes/pipex.h"

/* void	free_all_cmds(char **cmds)
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

static void	ft_free_rest(t_input **input, char **paths)
{
	int		i;
	t_input	*tmp;

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
} */

/*
{	if (pipex()->flag == 42)
		unlink(".temp");
	if (pipex()->fd_in != -1)
		close(pipex()->fd_in);
	if (pipex()->fd_out != -1)
		close(pipex()->fd_out);
	if (error != 0)
	{
		if (error == 1)
			ft_printf("Error:\nInvalid usage.\n");
		else if (error == 2)
		{
			input = pipex()->first;
			ft_free_rest(&input, pipex()->paths);
		}
		exit(1);
	}
	input = pipex()->first;
	ft_free_rest(&input, pipex()->paths);
	exit(0);
} */

void	exit_pipex(t_pipe *pipex)
{
	free_array((void **)pipex->env);
	free_array((void **)pipex->cmd_paths);
	free_array((void **)pipex->env_paths);
	free_pointer((void **)pipex->last_path);
	free_pointer((void **)pipex->pids);
	free_pointer((void **)pipex->fds);
}

void	pos_execute(t_pipe *pipex)
{
	int		status;
	size_t	i;

	i = -1;
	fd_close(pipex);
	while(++i < pipex->argc)
	{
		waitpid(pipex->pids[i], &status, 0);
		if (WIFEXITED(status))
			minis()->error_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			minis()->error_status = 128 + WTERMSIG(status);
	}
	exit_pipex(pipex);
}
