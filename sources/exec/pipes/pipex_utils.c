
#include "../../../includes/pipex.h"

void	first_child(t_pipe *pipex, t_input *input)
{
	get_fds(minis()->input, pipex->cmd_paths[0]);
	if (input->l_write < 3)
	{
		if (dup2(pipex->fds[0].fd[1], STDOUT_FILENO) < 0)
			return (ft_printf("Error in get_fds dup2(3)"), (void)pipex);
	}
	if (is_builtin(input->cmd))
		return (minis()->pipex = pipex, minis()->pipe_flag = 0, \
			ft_exec_builtin(minis()->input->cmd, minis()->input->args));
	close_one_fd(pipex);
	fd_close_all(minis()->input);
	true_execve(pipex->cmd_paths[0], pipex->env);
}

int	good_files(t_input *cmd)
{
	t_fd	*f;

	f = cmd->fd;
	while (f)
	{
		if (f->fd == -1)
			return (0);
		f = f->next;
	}
	return (1);
}

static char	**full_argv(t_input *input)
{
	int		i;
	char	**argv;

	argv = ft_calloc(array_len(input->args) + 2, sizeof(char *));
	argv[0] = ft_strdup(input->cmd);
	i = 0;
	while (input->args[i])
	{
		argv[i + 1] = ft_strdup(input->args[i]);
		i++;
	}
	argv[i + 1] = NULL;
	return (argv);
}

void	true_execve(char *path, char **envp)
{
	char	**argv;

	argv = full_argv(minis()->input);
	if (execve(path, argv, envp))
		return (free_array((void **)argv));
}
