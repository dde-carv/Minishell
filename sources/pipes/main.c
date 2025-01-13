/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:05:09 by dde-carv          #+#    #+#             */
/*   Updated: 2025/01/08 11:49:36 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

t_pipe	*data(void)
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

static t_cmd	*set_input(int argc, char **argv, char **paths)
{
	int		i;
	t_cmd	*input;
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

static t_cmd	*init_pipex(int argc, char **argv, char **envp)
{
	t_cmd	*input;

	if (!ft_strncmp(argv[1], "here_doc", 9))
		here_doc_main(argc, argv);
	else
	{
		data()->fd_in = open(argv[1], O_RDONLY);
		if (data()->fd_in == -1)
			exit_pipex(NULL, 1);
		data()->fd_out = open(argv[argc - 1], \
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (data()->fd_out == -1)
			exit_pipex(NULL, 1);
	}
	data()->paths = get_path(envp);
	input = set_input(argc, argv, data()->paths);
	data()->first = input;
	return (input);
}

int	pipex(int argc, char **argv, char **envp)
{
	t_cmd	*input;

	input = init_pipex(argc, argv, envp);
	father_son(input, envp);

	return (0);
}
