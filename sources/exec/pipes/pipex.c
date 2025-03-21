/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:05:09 by dde-carv          #+#    #+#             */
/*   Updated: 2025/03/21 16:38:01 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
static void	exec_one(t_pipe *pipex) //!! Still need work
{
	if (ft_strcmp("", pipex->cmd_paths[0]) == 0)
		return (pipex->argc -= 1, (void)pipex);
	if (pipe(pipex->fds[0].fd) < 0)
		return (ft_printf("Error in pipe 1cmd creation"), (void)pipex);
	if (!*minis()->input->cmd)
		return ;
	pipex->pids[0] = fork();
	if (pipex->pids[0] < 0)
		return (ft_printf("Error in fork 1cmd creation"), free_array(pipex->pids), (void)pipex);
	if (pipex->pids[0] == 0)
	{

	}
}

static void	execute_pipes(t_pipe *pipex)
{
	//int		i;
	//int		j;
	//t_input	*cmd;

	if (pipex->argc == 1)
		return (exec_one(pipex));
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
	/* if (!check_for_hd(minis()->input))
		return ; */
	init_pipex(&pipex);
	/* if (ft_father_son(input, env) == -1)
		minis()->error_status = 1; //????? */
	execute_pipes(&pipex);
	//pos_execute(); // !! wait for pids and closes fds
	exit_pipex(&pipex);
}
