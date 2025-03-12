/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   family.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:50:58 by dde-carv          #+#    #+#             */
/*   Updated: 2025/03/11 14:05:46 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

static void	prep_father(t_input *input)
{
	if (!input->prev)
		dup2(pipex()->fd_in, 0);
	else
	{
		dup2(input->prev->fd->fd[0], 0);
		close(input->prev->fd->fd[0]);
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
		dup2(input->fd->fd[1], 1);
	if (input->fd->fd[0] != -1)
		close(input->fd->fd[0]);
	if (input->fd->fd[1] != -1)
		close(input->fd->fd[1]);
	close(pipex()->fd_in);
	if (input->next)
		close(pipex()->fd_out);
	if (!input->path)
		ft_printf("lol 69\n");									//!!!!!
		//exit_pipex(input, 2);
	if (execve(input->path, input->args, envp) == -1)
		ft_printf("lol 70\n");									//!!!!!
		//exit_pipex(input, 2);
}

static void	after_father(t_input *input)
{
	if (input->fd->fd[1] != -1)
		close(input->fd->fd[1]);
	if (!input->next)
		if (input->fd->fd[0] != -1)
			close(input->fd->fd[0]);
}

int	father_son(t_input *input, char **envp)
{
	while (input)
	{
		prep_father(input);
		pipex()->pid = fork();
		if (pipex()->pid == -1)
			ft_printf("lol 71\n");									//!!!!!
			//exit_pipex(input, 2);
		if (pipex()->pid == 0)
			son(input, envp);
		after_father(input);
		input = input->next;
	}
	input = minis()->input;
	while (input)
	{
		waitpid(-1, NULL, 0);
		input = input->next;
	}
	ft_printf("lol 72\n");									//!!!!!
	//exit_pipex(NULL, 0);
	return(0);
}
