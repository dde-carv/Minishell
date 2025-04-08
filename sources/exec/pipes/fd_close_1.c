/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_close_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:19:26 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/08 10:19:27 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

void	fd_close_all(t_input *input)
{
	t_input	*tmp;

	tmp = input;
	while (tmp)
	{
		close_fd(tmp);
		tmp = tmp->next;
	}
}
