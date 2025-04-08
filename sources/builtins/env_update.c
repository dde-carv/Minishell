/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:18:25 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/08 10:18:26 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shlvl_update(void)
{
	int		n;
	char	*nbr;
	char	*tmp;

	if (hashmap_search(minis()->env, "SHLVL"))
	{
		tmp = ft_strdup(hashmap_search(minis()->env, "SHLVL"));
		hashmap_delete(minis()->env, "SHLVL");
		n = ft_atoi(tmp);
		n = n + 1;
		nbr = ft_itoa(n);
		insert_in_table("SHLVL", nbr, minis()->env);
		free(tmp);
		free(nbr);
	}
	else
		insert_in_table("SHLVL", "0", minis()->env);
}

void	update_under(void)
{
	t_input	*tmp;

	tmp = minis()->input;
	while (tmp->next)
		tmp = tmp->next;
	if (!*tmp->cmd)
		return ;
	if (*tmp->args)
	{
		if (hashmap_search(minis()->env, "_"))
		{
			hashmap_delete(minis()->env, "_");
			insert_in_table("_",
				tmp->args[array_len(tmp->args) - 1], minis()->env);
		}
	}
	else
	{
		if (hashmap_search(minis()->env, "_"))
		{
			hashmap_delete(minis()->env, "_");
			insert_in_table("_", tmp->cmd, minis()->env);
		}
	}
}
