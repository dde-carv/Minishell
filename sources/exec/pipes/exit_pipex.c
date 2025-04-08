/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:19:21 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/08 10:19:22 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

void	exit_pipex(t_pipe *pipex)
{
	free_array((void **)pipex->env);
	free_array((void **)pipex->cmd_paths);
	free_array((void **)pipex->env_paths);
	free_pointer((void **)pipex->last_path);
	free_pointer((void **)pipex->pids);
	free_pointer((void **)pipex->fds);
}

void	pos_execute(t_pipe *pipex)
{
	int		status;
	size_t	i;

	i = -1;
	status = 0;
	fd_close(pipex);
	while (++i < pipex->argc)
	{
		minis()->signal = 2;
		load_signals();
		waitpid(pipex->pids[i], &status, 0);
		if (WIFEXITED(status))
			minis()->error_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			minis()->error_status = 128 + WTERMSIG(status);
	}
	exit_pipex(pipex);
}
