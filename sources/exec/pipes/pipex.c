/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:15:04 by dde-carv          #+#    #+#             */
/*   Updated: 2025/02/25 11:19:24 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

	pipex()->flag = 0;
	pipex()->paths = get_path(envp);
	input = set_input(argc, argv, pipex()->paths);
	pipex()->first = input;
	return (input);
}

/* int	main(int argc, char **argv, char **envp)
{
	t_input	*input;

	if (envp[0] == NULL)
		exit_pipex(NULL, 1);
	if (argc == 5)
	{
		if (!check_empty(argc, argv))
			exit_pipex(NULL, 1);
		input = init_pipex(argc, argv, envp);
		father_son(input, envp);
	}
	else
	{
		ft_printf("Bad syntax:\n./pipex file1 \"cmd1\" \"cmd2\" file2\n");
		return (1);
	}
	return (0);
} */

void	ft_exec_pipex(t_input **input)
{
	t_input	*tmp;
	char	**env;
	int		pipe_flag;

	pipe_flag = 0;
	tmp = *input;
	while (tmp)
	{
		tmp->path = ft_check_path(tmp->cmd, pipex()->paths);
	}
}
