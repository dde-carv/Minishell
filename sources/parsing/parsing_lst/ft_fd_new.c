/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:26:03 by luiribei          #+#    #+#             */
/*   Updated: 2025/04/08 10:26:04 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_fd	*ft_fd_new(char *file_n, int fd, t_type type)
{
	t_fd	*n;

	n = ft_calloc(sizeof(t_fd), 1);
	if (!n)
		return (NULL);
	n->file_n = file_n;
	n->fd = fd;
	n->type = type;
	n->next = NULL;
	return (n);
}
