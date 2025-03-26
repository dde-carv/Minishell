
#include "../../../includes/pipex.h"

/* t_pipe	*data(void)
{
	static t_pipe	data;

	return (&data);
}

static int	check_empty(int argc, char **argv)
{
	int	i;
	int	j;
	int	blank;

	i = 1;
	while (i < argc)
	{
		j = 0;
		blank = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				blank++;
			j++;
		}
		if (blank == j)
			return (0);
		i++;
	}
	return (1);
}

static t_input	*set_input(int argc, char **argv, char **paths)
{
	int		i;
	t_input	*input;
	int		is_last;

	i = 2;
	is_last = (argc == 4);
	input = ft_newcmd(argv[i], check_path(argv[i], paths), is_last);
	i++;
	while (argv[i] && i < (argc - 1))
	{
		is_last = (i == argc - 2);
		ft_addcmd(&input, ft_newcmd(argv[i], check_path(argv[i], paths), \
			is_last));
		i++;
	}
	return (input);
}

static t_input	*init_pipex(int argc, char **argv, char **envp)
{
	t_input	*input;

	if (!ft_strncmp(argv[1], "here_doc", 9))
		here_doc_main(argc, argv);
	else
	{
		pipex()->fd_in = open(argv[1], O_RDONLY);
		if (pipex()->fd_in == -1)
			exit_pipex(NULL, 1);
		pipex()->fd_out = open(argv[argc - 1], \
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (pipex()->fd_out == -1)
			exit_pipex(NULL, 1);
	}
	pipex()->paths = get_path(envp);
	input = set_input(argc, argv, pipex()->paths);
	pipex()->first = input;
	return (input);
} */

/* static void	start_first(t_pipe *pipex)
{
	int	i;

	i = 0;
	if (pipe(pipex->fds[0].fd) < 0)
		return (ft_printf("Error in pipe first pipe creation"), (void)pipex);
	if (!good_files(minis()->input) || !*minis()->input->cmd)
		return ;
	pipex->pids[i] = fork();
	if (pipex->pids[i] < 0)
		return (ft_printf("Error in fork 1 pipe creation"), free_pointer(pipex->pids), (void)pipex);
	if (pipex->pids[i] == 0)
	{
		// ?? verify signals
		first_child(pipex, minis()->input);
	}
} */

/* void	start_rest(t_pipe *pipex, t_input *input, char *cmd_path, int i)
{
	if (!good_files(minis()->input) || !*minis()->input->cmd)
		return ;
	pipex->pids[i] = fork();
	if (pipex->pids[i] < 0)
		return (ft_printf("Error in fork rest pipe creation"), free_pointer(pipex->pids), (void)pipex);
	if (pipex->pids[i] == 0)
	{
		get_fds(input, cmd_path);
		l_fd_update(input, pipex, i); // TODO
		if (is_builtin(input->cmd))
			return (minis()->pipex = pipex, minis()->pipe_flag = i, ft_exec_builtin(minis()->input->cmd, minis()->input->args));

	}
} */

//!! Still need work
static void	exec_one(t_pipe *pipex)
{
	if (ft_strcmp("", pipex->cmd_paths[0]) == 0)
		return ;
	if (pipe(pipex->fds[0].fd) < 0)
		return (ft_printf("Error in pipe 1cmd creation"), (void)pipex);
	if (!*minis()->input->cmd)
		return (close_one_fd(pipex));
	if (!good_files(minis()->input))
		return (close_one_fd(pipex), (void)pipex);
	pipex->pids[0] = fork();
	if (pipex->pids[0] < 0)
		return (ft_printf("Error in fork 1cmd creation"), free_pointer(pipex->pids), (void)pipex);
	if (pipex->pids[0] == 0)
	{
		get_fds(minis()->input, pipex->cmd_paths[0]);
		// ? Verify if builtin is needed here
		fd_close(pipex);
		fd_close_all(minis()->input);
		true_execve(pipex->cmd_paths[0], pipex->env);
	}
	return ;
}

static void	execute_pipes(t_pipe *pipex)
{
	//int		i;
	//int		j;
	//t_input	*tmp;

	if (pipex->argc == 1)
		return (exec_one(pipex));
/* 	start_first(pipex);
	tmp = minis()->input;
	i = 0;
	j = pipex->argc - 1;
	while (++i < j && tmp)
	{
		tmp = tmp->next;
		if (pipe(pipex->fds[i].fd) < 0)
			return (ft_printf("Fail pipe creation(2)"), (void)pipex);
		start_rest(pipex, i, pipex->cmd_paths[i], tmp);
	} */
}

static void	init_pipex(t_pipe *pipex)
{
	int	i;

	pipex->env_paths = ft_get_env_paths();
	pipex->argc = ft_input_lstsize(&minis()->input);
	pipex->pids = ft_calloc(sizeof(size_t), pipex->argc);
	if (!pipex->pids)
		return ;
	pipex->cmd_paths = ft_calloc(sizeof(char *), pipex->argc + 1);
	if (!pipex->cmd_paths)
		return (free(pipex->pids));
	i = pipex->argc;
	if (i > 1)
		i -= 1;
	pipex->fds = ft_calloc(sizeof(t_fds), i);
	if (!pipex->fds)
		return (free(pipex->pids), free(pipex->cmd_paths));
	get_cmd_path(pipex, minis()->input);
	pipex->env = hashmap_to_array();
}

// !!! DON'T forget to update the $_ variable after execution
void	ft_exec_pipex(void)
{
	t_pipe	pipex;

	pipex = (t_pipe){0};
	if (!check_for_hd(minis()->input))
		return ;
	init_pipex(&pipex);
	/* if (ft_father_son(input, env) == -1)
		minis()->error_status = 1; //????? */
	execute_pipes(&pipex);
	pos_execute(&pipex); // !! wait for pids and closes fds
	//exit_pipex(&pipex);
}
