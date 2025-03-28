
#include "../../../includes/pipex.h"

static t_input	*ft_lstinput_last(t_input *input, int *i)
{
	t_input	*tmp;

	*i = 0;
	tmp = input;
	while (tmp->next)
	{
		(*i)++;
		tmp = tmp->next;
	}
	return (tmp);
}
static int	get_write_file(t_fd *fd)
{
	t_fd	*f_d;
	t_type	type;
	char	*file_n;

	f_d = fd;
	file_n = NULL;
	while (f_d)
	{
		if (f_d->type == APPEND || f_d->type == TRUNCATE)
		{
			file_n = f_d->file_n;
			type = f_d->type;
		}
		f_d = f_d->next;
	}
	if (!file_n)
		return (0);
	if (type == APPEND)
		return (open(file_n, O_CREAT | O_APPEND | O_WRONLY, 0644));
	return(open(file_n, O_CREAT | O_TRUNC | O_WRONLY, 0644));
}


static void print_fd(t_input *input){
	t_fd *f;

	f = input->fd;

	while (f)
	{
		ft_putnbr_fd(f->fd, 1);
		ft_putendl_fd(f->file_n, 1);
		f = f->next;
	}
}


void	rest_children(t_pipe *pipex, char *cmd_path, t_input *input)
{
	int	i;
	t_input	*tmp;


	tmp = ft_lstinput_last(input, &i);
	print_fd(tmp);
	if (!check_valid(input, cmd_path))
		return ;
	minis()->signal = 3;
	pipex->pids[i] = fork();
	if (pipex->pids[i] < 0)
		return (ft_printf("Error in fork rest_children pipe creation"), free_pointer(pipex->pids), (void)pipex);
	if (pipex->pids[i] == 0)
	{
		input->l_write = get_write_file(input->fd);
		get_fds(input, cmd_path);
			if (dup2(pipex->fds[i - 1].fd[0], STDIN_FILENO) < 0)
				return (ft_printf("Error in dup2 rest_children"), (void)cmd_path);
		if (is_builtin(input->cmd))
			return (minis()->pipex = pipex, minis()->pipe_flag = -1, \
				ft_exec_builtin(input->cmd, input->args));
		fd_close(pipex);
		fd_close_all(input);
		true_execve(cmd_path, input, pipex->env);
	}
	return ;
}

int	check_valid(t_input *input, char *cmd_path)
{
	if (!is_builtin(input->cmd) && access(cmd_path, F_OK) != 0)
		return (0);
	if (!good_files(input) || !*input->cmd)
		return (0);
	return (1);
}

void	first_child(t_pipe *pipex, t_input *input)
{
	get_fds(input, pipex->cmd_paths[0]);
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
	true_execve(pipex->cmd_paths[0], input, pipex->env);
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

void	true_execve(char *path, t_input *input, char **envp)
{
	char	**argv;

	argv = full_argv(input);
	if (execve(path, argv, envp) == -1)
		return (free_array((void **)argv));
}
