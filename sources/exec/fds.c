/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:20:22 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/08 10:20:23 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_last_w(t_fd *fd)
{
	t_fd	*f_d;
	int		file_d;

	f_d = fd;
	file_d = 1;
	while (f_d)
	{
		if (f_d->type == TRUNCATE || f_d->type == APPEND)
			file_d = f_d->fd;
		f_d = f_d->next;
	}
	return (file_d);
}

static int	get_last_r(t_fd *fd)
{
	t_fd	*f_d;
	int		file_d;
	int		here_flag;

	f_d = fd;
	file_d = 1;
	here_flag = 0;
	while (f_d)
	{
		if (f_d->type == REVERSE && !here_flag)
			file_d = f_d->fd;
		else if (f_d->type == HEREDOC)
		{
			file_d = f_d->fd;
			here_flag = 1;
		}
		f_d = f_d->next;
	}
	return (file_d);
}

int	handle_fd(t_input **input)
{
	t_fd	*fd;

	fd = (*input)->fd;
	while (fd)
	{
		if (fd->type == TRUNCATE)
			fd->fd = open(fd->file_n, O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (fd->type == APPEND)
			fd->fd = open(fd->file_n, O_CREAT | O_APPEND | O_WRONLY, 0664);
		if (fd->type == REVERSE)
			fd->fd = open(fd->file_n, O_RDONLY, 0644);
		if (fd->type == HEREDOC)
			fd->fd = 1000;
		if (fd->fd == -1)
			error_mess(fd->file_n, NO_FILE_OR_DIR, 1);
		fd = fd->next;
	}
	(*input)->l_write = get_last_w((*input)->fd);
	(*input)->l_read = get_last_r((*input)->fd);
	return (1);
}
