/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:19:39 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/08 10:19:40 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

static int	get_read_file(t_fd *fd)
{
	t_fd	*f_d;
	char	*file_n;

	f_d = fd;
	file_n = NULL;
	while (f_d)
	{
		if (f_d->type == HEREDOC || f_d->type == REVERSE)
			file_n = f_d->file_n;
		f_d = f_d->next;
	}
	if (!file_n)
		return (0);
	return (open(file_n, O_RDONLY, 0644));
}

static int	get_write_file(t_fd *fd)
{
	t_fd	*f_d;
	t_type	type;
	char	*file_n;

	f_d = fd;
	file_n = NULL;
	while (f_d)
	{
		if (f_d->type == APPEND || f_d->type == TRUNCATE)
		{
			file_n = f_d->file_n;
			type = f_d->type;
		}
		f_d = f_d->next;
	}
	if (!file_n)
		return (0);
	if (type == APPEND)
		return (open(file_n, O_CREAT | O_APPEND | O_WRONLY, 0644));
	return (open(file_n, O_CREAT | O_TRUNC | O_WRONLY, 0644));
}

void	get_fds(t_input *input, char *cmd_path)
{
	input->l_read = get_read_file(input->fd);
	input->l_write = get_write_file(input->fd);
	if (input->l_read >= 3)
	{
		if (dup2(input->l_read, STDIN_FILENO) < 0)
			return (ft_printf("Error in get_fds dup2(1)"), (void)cmd_path);
	}
	if (input->l_write >= 3)
	{
		if (dup2(input->l_write, STDOUT_FILENO) < 0)
			return (ft_printf("Error in get_fds dup2(2)"), (void)cmd_path);
	}
}

void	fd_update(t_input *input, t_pipe *pipex, int i)
{
	if (input->l_read < 3)
	{
		if (dup2(pipex->fds[i - 1].fd[0], STDIN_FILENO) < 0)
			return (ft_printf("Error in get_fds dup2(4)"), (void)i);
	}
	if (input->l_write < 3)
	{
		if (dup2(pipex->fds[i].fd[1], STDOUT_FILENO) < 0)
			return (ft_printf("Error in get_fds dup2(5)"), (void)i);
	}
}
