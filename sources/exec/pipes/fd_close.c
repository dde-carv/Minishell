/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:19:34 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/08 10:19:35 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

void	ft_close(int fd)
{
	if (fd > 0 && fd != STDERR_FILENO && \
		fd != STDIN_FILENO && fd != STDOUT_FILENO)
		close(fd);
}

void	close_one_fd(t_pipe *pipex)
{
	ft_close(pipex->fds[0].fd[0]);
	ft_close(pipex->fds[0].fd[1]);
}

void	fd_close_m(t_pipe *pipex, int i)
{
	int	k;

	k = 0;
	while (k <= i)
	{
		ft_close(pipex->fds[k].fd[0]);
		ft_close(pipex->fds[k].fd[1]);
		k++;
	}
}

void	fd_close(t_pipe *pipex)
{
	size_t	i;

	i = 0;
	if (pipex->argc == 1)
		close_one_fd(pipex);
	while (i < (pipex->argc - 1))
	{
		ft_close(pipex->fds[i].fd[0]);
		ft_close(pipex->fds[i].fd[1]);
		i++;
	}
}

void	close_fd(t_input *input)
{
	t_fd	*tmp;

	tmp = input->fd;
	while (tmp)
	{
		if (tmp->fd != -1 && tmp->fd > 2)
		{
			ft_close(tmp->fd);
			tmp->fd = 1;
		}
		if (input->l_read >= 3)
			ft_close(input->l_read);
		if (input->l_write >= 3)
			ft_close(input->l_write);
		tmp = tmp->next;
	}
}
