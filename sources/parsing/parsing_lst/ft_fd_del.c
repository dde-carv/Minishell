/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:26:00 by luiribei          #+#    #+#             */
/*   Updated: 2025/04/08 10:26:01 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_fd_delone(t_fd **lst)
{
	t_fd	*temp;

	temp = *lst;
	free_pointer(temp->file_n);
	if (temp->fd > 0)
		close(temp->fd);
	free(temp);
}

void	ft_fd_del(t_fd	**fd)
{
	t_fd	*list_t;
	t_fd	*list_temp;

	list_t = *fd;
	if (!*fd)
		return ;
	while (list_t)
	{
		list_temp = list_t->next;
		ft_fd_delone(&list_t);
		list_t = list_temp;
	}
	*fd = NULL;
}
