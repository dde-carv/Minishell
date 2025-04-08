/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expantion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:25:19 by luiribei          #+#    #+#             */
/*   Updated: 2025/04/08 10:32:52 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expantions(char **s)
{
	char		in_quotes;
	char		*str;
	int			i;

	if (!s || !*s)
		return ;
	str = *s;
	i = -1;
	in_quotes = 0;
	while (str[++i])
	{
		update_quote_state(str[i], &in_quotes);
		if (str[i] == '$' && str[i + 1]
			&& (str[i + 1] == '\'' || str[i + 1] == '"'))
			continue ;
		if (str[i] == '$' && str[i + 1]
			&& (!in_quotes || in_quotes == '"')
			&& (ft_isalnum(str[i + 1]) || str[i + 1] == '?'
				|| str[i + 1] == '_'))
			str[i] = 2;
	}
}

static void	expand_error_status(char **sp, char *new, int *j)
{
	char	*error_str;
	int		k;

	error_str = ft_itoa(minis()->error_status);
	k = 0;
	while (error_str[k])
		new[(*j)++] = error_str[k++];
	free(error_str);
	(*sp)++;
}

static void	expand_value(char **sp, char *new, int *j, char *value)
{
	while (**sp && (ft_isalnum(**sp) || **sp == '_' || **sp == '?'))
	{
		if (ft_isdigit(**sp))
		{
			(*sp)++;
			break ;
		}
		(*sp)++;
	}
	while (*value)
		new[(*j)++] = *value++;
}

char	*sub_expantion(char *str, char *value)
{
	char	quote;
	char	*new;
	char	*s;
	int		j;

	if (!value)
		value = "";
	new = ft_calloc(ft_strlen(str) + ft_strlen(value) + 1, sizeof(char));
	if (!new)
		return (ft_strdup(""));
	s = str;
	j = 0;
	while (*s && *s != 2)
		new[j++] = *s++;
	if (*s == 2)
	{
		s++;
		if (*s == '\'' || *s == '"')
		{
			new[j++] = '$';
			quote = *s;
			new[j++] = quote;
			s++;
			while (*s && *s != quote)
				new[j++] = *s++;
			if (*s == quote)
				new[j++] = *s++;
		}
		if (*s == '?')
			expand_error_status(&s, new, &j);
		else
			expand_value(&s, new, &j, value);
	}
	while (*s)
		new[j++] = *s++;
	free(str);
	return (new);
}
