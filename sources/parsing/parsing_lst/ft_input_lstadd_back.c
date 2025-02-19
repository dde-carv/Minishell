/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_lstadd_back.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:37:38 by luiribei          #+#    #+#             */
/*   Updated: 2025/02/19 09:37:39 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static t_input	*ft_lst_last(t_input *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_input_lstadd_back(t_input **lst, t_input *n)
{
	t_input	*last;

	last = ft_lst_last(*lst);
	if (!last)
		*lst = n;
	else
		last->next = n;
}
