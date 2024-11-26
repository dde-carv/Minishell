/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:00:43 by dde-carv          #+#    #+#             */
/*   Updated: 2024/05/07 15:27:48 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

//Deletes and frees the given node and every successor of that node.

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (lst && del)
	{
		while (*lst)
		{
			tmp = *lst;
			*lst = (*lst)->next;
			ft_lstdelone(tmp, del);
		}
	}
}
