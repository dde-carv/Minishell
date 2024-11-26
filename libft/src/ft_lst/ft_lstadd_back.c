/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:14:21 by dde-carv          #+#    #+#             */
/*   Updated: 2024/05/07 15:27:38 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

//Adds the node ’new’ at the end of the list.

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		if (!*lst)
			*lst = new;
		else
			ft_lstlast(*lst)->next = new;
	}
}
