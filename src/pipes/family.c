/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   family.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:50:58 by dde-carv          #+#    #+#             */
/*   Updated: 2024/11/20 11:53:07 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

static void	prep_father(t_cmd *input)
{
	if (!input->prev)
		dup2(data()->fd_in, 0);
	else
	{
		dup2(input->prev->fd[0], 0);
		close(input->prev->fd[0]);
	}
}

static void	son(t_cmd *input, char **envp)
{
	if (input->next == NULL)
	{
		dup2(data()->fd_out, 1);
		close(data()->fd_out);
	}
	else
		dup2(input->fd[1], 1);
	if (input->fd[0] != -1)
		close(input->fd[0]);
	if (input->fd[1] != -1)
		close(input->fd[1]);
	close(data()->fd_in);
	if (input->next)
		close(data()->fd_out);
	if (!input->path)
		exit_pipex(input, 2);
	if (execve(input->path, input->av, envp) == -1)
		exit_pipex(input, 2);
}

static void	after_father(t_cmd *input)
{
	if (input->fd[1] != -1)
		close(input->fd[1]);
	if (!input->next)
		if (input->fd[0] != -1)
			close(input->fd[0]);
}

void	father_son(t_cmd *input, char **envp)
{
	while (input)
	{
		prep_father(input);
		data()->pid = fork();
		if (data()->pid == -1)
			exit_pipex(input, 2);
		if (data()->pid == 0)
			son(input, envp);
		after_father(input);
		input = input->next;
	}
	input = data()->first;
	while (input)
	{
		waitpid(-1, NULL, 0);
		input = input->next;
	}
	exit_pipex(NULL, 0);
}
