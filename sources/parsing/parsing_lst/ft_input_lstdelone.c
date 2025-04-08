/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_lstdelone.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:26:12 by luiribei          #+#    #+#             */
/*   Updated: 2025/04/08 10:26:47 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_input_lstdelone(t_input **lst)
{
	t_input	*temp;

	temp = *lst;
	free_pointer(temp->cmd);
	free_pointer(temp->arg);
	free_pointer(temp->path);
	free_array((void **)temp->args);
	ft_fd_del(&temp->fd);
	free(temp);
}
