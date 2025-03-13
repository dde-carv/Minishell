/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:05:09 by dde-carv          #+#    #+#             */
/*   Updated: 2025/03/13 12:30:09 by dde-carv         ###   ########.fr       */
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

void	ft_exec_pipex(t_input *input) // !!! DON'T forget to update the $_ variable after execution
{
	t_input	*tmp;
	char	**env;

	tmp = input;
	pipex()->paths = ft_get_paths();
	while (tmp)
	{
		tmp->path = ft_check_path(tmp->cmd, pipex()->paths);
		ft_printf("full cmd: %s\n", tmp->path);										//!!!!
		//pipe(tmp->fd->fd);// == -1;
		/* if (pipe(tmp->fd->fd) == -1)
		return ; */
		//return (exit_pipex(tmp, 69)); // * Still need to work on this
		tmp = tmp->next;
	}
	ft_printf("full cmd: %s\n", tmp->path);										//!!!!
	env = hashmap_to_array();
	/* if (father_son(input, env) == -1)
		minis()->error_status = 1; //????? */
	free_array(pipex()->paths);
	free_array(env);
}
