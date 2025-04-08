/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:24:55 by luiribei          #+#    #+#             */
/*   Updated: 2025/04/08 10:24:56 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_args(t_input **input, char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i++])
		;
	(*input)->args = ft_calloc(sizeof(char *), i + 1);
	i = 1;
	j = 0;
	while (s[i++])
		(*input)->args[j++] = ft_strdup(s[i]);
	(*input)->args[j++] = NULL;
}

static void	join_args(t_input **input, char **s)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((*input)->args[i++])
		;
	while (s[j++])
		;
	str = ft_calloc(i + j + 1, sizeof(char *));
	str[i] = NULL;
	i = 0;
	while ((*input)->args[i++])
		str[i] = ft_strdup((*input)->args[i]);
	j = 0;
	while (s[j++])
		str[i++] = ft_strdup(s[j]);
	free_array((void **)s);
	free_array((void **)(*input)->args);
	(*input)->args = str;
}

void	args(t_input **input)
{
	char	**s;
	int		i;

	s = split_value((*input)->cmd);
	free((*input)->cmd);
	(*input)->cmd = ft_strdup(s[0]);
	add_args(input, s);
	i = 0;
	while (s[i++])
		free(s[i]);
	free(s[i]);
	free(s);
	join_args(input, split_value((*input)->arg));
}
