/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_lstdelone.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:37:42 by luiribei          #+#    #+#             */
/*   Updated: 2025/02/19 09:37:43 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	free_args(char **s)
{
	int	i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

void	ft_input_lstdelone(t_input **lst)
{
	t_input	*temp;

	temp = *lst;
	if (temp->arg)
		free(temp->arg);
	if (temp->cmd)
		free(temp->cmd);
	free_args(temp->args);
	free(temp);
}
