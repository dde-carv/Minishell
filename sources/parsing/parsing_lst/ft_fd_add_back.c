/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:25:56 by luiribei          #+#    #+#             */
/*   Updated: 2025/04/08 10:25:57 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_fd	*ft_lst_last(t_fd *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_fd_add_back(t_fd **lst, t_fd *n)
{
	t_fd	*last;

	last = ft_lst_last(*lst);
	if (!last)
		*lst = n;
	else
		last->next = n;
}
