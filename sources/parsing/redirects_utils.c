/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:25:31 by luiribei          #+#    #+#             */
/*   Updated: 2025/04/08 17:24:08 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* This function splits a processed string into a command and its arguments.
It searches for the first space in the string and uses that as a delimiter.
If a space is found, the string is split: the part before the space becomes
the new command and the part after becomes the new argument.
If no space is found, the whole string becomes the command with an empty
argument.
Before updating, the function frees the original command and argument strings
held in the t_input structure. */
void	update_cmd_args(t_input **cmd, char *processed_str)
{
	char	*space_pos;

	space_pos = ft_strchr(processed_str, ' ');
	if (space_pos)
	{
		*space_pos = '\0';
		free((*cmd)->cmd);
		(*cmd)->cmd = ft_strdup(processed_str);
		free((*cmd)->arg);
		(*cmd)->arg = ft_strdup(space_pos + 1);
	}
	else
	{
		free((*cmd)->cmd);
		(*cmd)->cmd = ft_strdup(processed_str);
		free((*cmd)->arg);
		(*cmd)->arg = ft_strdup("");
	}
}

char	*remove_all_quotes(char *s)
{
	int		i;
	int		j;
	char	*result;

	result = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != '\'' && s[i] != '"')
			result[j++] = s[i];
		i++;
	}
	result[j] = '\0';
	return (result);
}

t_type	get_redirection_type(const char *str, int *i)
{
	t_type	type;

	if (str[*i] == '>' && str[*i + 1] == '>')
	{
		type = APPEND;
		(*i)++;
	}
	else if (str[*i] == '<' && str[*i + 1] == '<')
	{
		type = HEREDOC;
		(*i)++;
	}
	else if (str[*i] == '>')
		type = TRUNCATE;
	else
		type = REVERSE;
	return (type);
}

char	*extract_filename(const char *s, int *i)
{
	int		start;
	char	*fname;
	char	quote;

	if (s[*i] == '\'' || s[*i] == '"')
	{
		quote = s[*i];
		(*i)++;
		start = *i;
		while (s[*i] && s[*i] != quote)
			(*i)++;
		fname = ft_substr(s, start - 1, (*i - start) + 2);
		if (s[*i] == quote)
			(*i)++;
	}
	else
	{
		start = *i;
		while (s[*i] && s[*i] != ' ' && s[*i] != '<' && s[*i] != '>')
			(*i)++;
		fname = ft_substr(s, start, *i - start);
	}
	return (fname);
}
