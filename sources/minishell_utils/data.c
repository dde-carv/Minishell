/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:20:30 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/08 10:20:31 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_global	*minis(void)
{
	static t_global		data;
	static t_minishell	ms;
	static t_hashmap	env;
	static t_hashmap	non_value_vars;

	if (!data.ms)
	{
		data.ms = &ms;
		data.input = NULL;
		data.pipex = NULL;
		data.env = &env;
		data.non_value_vars = &non_value_vars;
	}
	return (&data);
}
