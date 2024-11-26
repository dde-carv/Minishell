/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:16:55 by dde-carv          #+#    #+#             */
/*   Updated: 2024/05/07 15:28:03 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

//Iterates the list ’lst’ and applies the function ’f’ on the
// content of each node. Uses 'del' function if needed.
//Returns the new list or NULL if the allocation fails.

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;

	if (!lst)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		if (f)
			new_elem = ft_lstnew(f(lst->content));
		else
			new_elem = ft_lstnew(lst->content);
		if (!new_elem)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
}
