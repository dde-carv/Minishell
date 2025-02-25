/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   family.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:50:58 by dde-carv          #+#    #+#             */
/*   Updated: 2025/02/24 16:02:57 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	prep_father(t_input *input)
{
	if (!input->prev)
		dup2(pipex()->fd_in, 0);
	else
	{
		dup2(input->prev->fd[0], 0);
		close(input->prev->fd[0]);
	}
}

static void	son(t_input *input, char **envp)
{
	if (input->next == NULL)
	{
		dup2(pipex()->fd_out, 1);
		close(pipex()->fd_out);
	}
	else
		dup2(input->fd[1], 1);
	if (input->fd[0] != -1)
		close(input->fd[0]);
	if (input->fd[1] != -1)
		close(input->fd[1]);
	close(pipex()->fd_in);
	if (input->next)
		close(pipex()->fd_out);
	if (!input->path)
		exit_pipex(input, 2);
	if (execve(input->path, input->av, envp) == -1)
		exit_pipex(input, 2);
}

static void	after_father(t_input *input)
{
	if (input->fd[1] != -1)
		close(input->fd[1]);
	if (!input->next)
		if (input->fd[0] != -1)
			close(input->fd[0]);
}

void	father_son(t_input *input, char **envp)
{
	while (input)
	{
		prep_father(input);
		pipex()->pid = fork();
		if (pipex()->pid == -1)
			exit_pipex(input, 2);
		if (pipex()->pid == 0)
			son(input, envp);
		after_father(input);
		input = input->next;
	}
	input = pipex()->first;
	while (input)
	{
		waitpid(-1, NULL, 0);
		input = input->next;
	}
	exit_pipex(NULL, 0);
}
