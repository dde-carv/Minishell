/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus(pipex).c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:05:09 by dde-carv          #+#    #+#             */
/*   Updated: 2025/02/24 16:02:57 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
}

int	main(int argc, char **argv, char **envp)
{
	t_input	*input;

	if (envp[0] == NULL)
		exit_pipex(NULL, 1);
	if (argc >= 5 || (argc > 5 && !ft_strncmp(argv[1], "here_doc", 9)))
	{
		if (!check_empty(argc, argv))
			exit_pipex(NULL, 1);
		input = init_pipex(argc, argv, envp);
		father_son(input, envp);
	}
	else
	{
		ft_printf("Bad syntax:\n./pipex file1 cmd1 cmd2 cmd3 ... file2\n\
			or\n./pipex here_doc LIMITER cmd1 cmd2 file\n");
		return (1);
	}
	return (0);
}
