/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:20:04 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/08 10:20:05 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	rest_children(t_pipe *pipex, char *cmd_path, t_input *input)
{
	int		i;
	t_input	*tmp;

	tmp = ft_lstinput_last(input, &i);
	if (!check_valid(tmp, cmd_path))
		return ;
	pipex->pids[i] = fork();
	if (pipex->pids[i] < 0)
		return (free_pointer(pipex->pids), (void)pipex);
	if (pipex->pids[i] == 0)
	{
		get_fds(tmp, cmd_path);
		if (tmp->l_read < 3)
		{
			if (dup2(pipex->fds[i - 1].fd[0], STDIN_FILENO) < 0)
				return ((void)cmd_path);
		}
		if (is_builtin(tmp->cmd))
			return (minis()->pipex = pipex, minis()->pipes = -1,
				ft_exec_builtin(tmp->cmd, tmp->args, STDOUT_FILENO, 1));
		fd_close(pipex);
		fd_close_all(tmp);
		true_execve(cmd_path, tmp, pipex->env);
	}
	return ;
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
		return (minis()->pipex = pipex, minis()->pipes = 0,
			ft_exec_builtin(input->cmd, input->args, STDOUT_FILENO, 1));
	close_one_fd(pipex);
	fd_close_all(input);
	true_execve(pipex->cmd_paths[0], input, pipex->env);
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
