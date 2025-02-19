/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_lstnew.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:37:46 by luiribei          #+#    #+#             */
/*   Updated: 2025/02/19 09:37:47 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

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
		exit(0);
	}
	input->arg = ft_strdup(arg);
	if (!input->arg)
	{
		ft_input_lstdelone(&input);
		exit(0);
	}
	input->args = NULL;
	input->next = NULL;
	return (input);
}
