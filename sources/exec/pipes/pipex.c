/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:20:09 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/08 16:37:09 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

void	start_rest(t_pipe *pipex, t_input *input, char *cmd_path, int i)
{
	if (!check_valid(input, cmd_path))
		return ;
	pipex->pids[i] = fork();
	if (pipex->pids[i] < 0)
		return (ft_printf("Error in fork rest pipe creation"),
			free_pointer(pipex->pids), (void)pipex);
	if (pipex->pids[i] == 0)
	{
		get_fds(input, cmd_path);
		fd_update(input, pipex, i);
		if (is_builtin(input->cmd))
			return (minis()->pipex = pipex, minis()->pipes = i,
				ft_exec_builtin(input->cmd, input->args, STDOUT_FILENO, 1));
		fd_close_m(pipex, i);
		fd_close_all(input);
		true_execve(cmd_path, input, pipex->env);
	}
}

void	start_first(t_pipe *pipex, t_input *input)
{
	int	i;

	i = 0;
	if (pipe(pipex->fds[0].fd) < 0)
		return (ft_printf("Error in pipe first pipe creation"), (void)pipex);
	if (!check_valid(input, pipex->cmd_paths[0]))
		return ;
	pipex->pids[i] = fork();
	if (pipex->pids[i] < 0)
		return (ft_printf("Error in fork 1 pipe creation"),
			free_pointer(pipex->pids), (void)pipex);
	if (pipex->pids[i] == 0)
	{
		minis()->signal = 3;
		load_signals();
		first_child(pipex, input);
	}
}

void	exec_one(t_pipe *pipex, t_input *input)
{
	if (ft_strcmp("", pipex->last_path) == 0)
		return (error_mess(input->cmd, NOT_FOUND, 127));
	if (pipe(pipex->fds[0].fd) < 0)
		return (ft_printf("Error in pipe 1cmd creation"), (void)pipex);
	if (!check_valid(input, pipex->last_path))
		return (close_one_fd(pipex), (void)pipex);
	pipex->pids[0] = fork();
	if (pipex->pids[0] < 0)
		return (ft_printf("Error in fork 1cmd creation"),
			free_pointer(pipex->pids), (void)pipex);
	if (pipex->pids[0] == 0)
	{
		get_fds(input, pipex->last_path);
		close_one_fd(pipex);
		fd_close_all(input);
		true_execve(pipex->last_path, input, pipex->env);
	}
	return ;
}

void	ft_exec_pipex(void)
{
	t_pipe	pipex;

	pipex = (t_pipe){0};
	if (!check_for_hd(minis()->input))
		return (g_sig = 0, (void)pipex);
	init_pipex(&pipex);
	execute_pipes(&pipex, minis()->input);
	pos_execute(&pipex);
	minis()->signal = 1;
	load_signals();
}
