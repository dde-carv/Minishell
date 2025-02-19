/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:37:22 by luiribei          #+#    #+#             */
/*   Updated: 2025/02/19 09:37:24 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_fd	*ft_lst_last(t_fd *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_fdadd_back(t_fd **lst, t_fd *n)
{
	t_fd	*last;

	last = ft_lst_last(*lst);
	if (!last)
		*lst = n;
	else
		last->next = n;
}