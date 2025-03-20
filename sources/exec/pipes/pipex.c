/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:05:09 by dde-carv          #+#    #+#             */
/*   Updated: 2025/03/20 16:14:09 by dde-carv         ###   ########.fr       */
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

/* static void	init_pipex(t_pipe *pipex)
{
	int	i;

	pipex->env_paths = ft_get_env_paths();
	pipex->argc = ft_input_lstsize(&minis()->input);
	pipex->pids = ft_calloc(sizeof(size_t), pipex->argc);
	if (!pipex->pids)
		return ;
	pipex->cmd_paths = ft_calloc(sizeof(char *), pipex->argc);
	if (!pipex->cmd_paths)
		return (free(pipex->pids));
	i = pipex->argc;
	if (i > 1)
		i -= 1;
	pipex->fds = ft_calloc(sizeof(t_fds), i);
	if (!pipex->fds)
		return (free(pipex->pids), free(pipex->cmd_paths));
	get_cmd_path(pipex, minis()->input);
	//ft_printf("input lst size: %d\n", pipex->argc);
} */

// !!! DON'T forget to update the $_ variable after execution
void	ft_exec_pipex(void)
{
	//t_input	*tmp;
	t_pipe	pipex;
	char	**env;

	pipex = (t_pipe){0};
	/* if (!check_for_hd(minis()->input))
		return ; */
	//init_pipex(&pipex); //? If enougth lines also allocate the command paths
/* 	while (tmp)
	{
		tmp->path = ft_check_path(tmp->cmd, pipex.env_paths);
		tmp = tmp->next;
	} */
	env = hashmap_to_array();
	/* if (ft_father_son(input, env) == -1)
		minis()->error_status = 1; //????? */
	/* free_array((void **)pipex.env_paths);
	free_array((void **)pipex.cmd_paths);
	free_array((void **)pipex.pids); */
	free_array((void **)env);
}
