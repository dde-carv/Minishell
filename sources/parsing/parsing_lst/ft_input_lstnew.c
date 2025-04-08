/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_lstnew.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:26:15 by luiribei          #+#    #+#             */
/*   Updated: 2025/04/08 10:26:50 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_input	*ft_input_lstnew(char *cmd, char *arg)
{
	t_input	*input;

	input = (t_input *)ft_calloc(1, sizeof(*input));
	if (!input)
		return (NULL);
	input->cmd = ft_strdup(cmd);
	if (!input->cmd)
	{
		free(input);
		return (NULL);
	}
	input->arg = ft_strdup(arg);
	if (!input->arg)
	{
		ft_input_lstdelone(&input);
		return (NULL);
	}
	input->l_read = 0;
	input->l_write = 1;
	input->fd = NULL;
	input->args = NULL;
	input->next = NULL;
	return (input);
}
