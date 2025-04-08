/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:25:39 by luiribei          #+#    #+#             */
/*   Updated: 2025/04/08 18:08:42 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Count how many words (tokens) there will be */
static int	words_count(char *str)
{
	char	in_quotes;
	int		words;
	int		i;

	in_quotes = 0;
	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (!str[i])
			return (0);
		words++;
		while (str[i] && ((str[i] != ' ' && !in_quotes) || (in_quotes)))
		{
			update_quote_state(str[i], &in_quotes);
			i++;
		}
	}
	return (words);
}

/* Find where the current word (token) ends */
static int	end_word(char *str, int start)
{
	char	in_quotes;
	int		i;

	if (!str || !*str)
		return (0);
	i = start;
	in_quotes = 0;
	while (str[i])
	{
		if ((str[i] == ' ' || str[i] == '\t') && !in_quotes)
			break ;
		update_quote_state(str[i], &in_quotes);
		i++;
	}
	return (i);
}

/* Create an array of tokens */
char	**split_value(char *str)
{
	char	**tokens;
	int		word_index;
	int		words;
	int		start;
	int		end;

	words = words_count(str);
	tokens = ft_calloc(words + 1, sizeof(char *));
	if (!tokens)
		return (NULL);
	word_index = -1;
	start = 0;
	while (++word_index < words)
	{
		while (str[start] == ' ' || str[start] == '\t')
			start++;
		end = end_word(str, start);
		if (end - start == 0)
			tokens[word_index] = ft_strdup("");
		else
			tokens[word_index] = ft_substr(str, start, end - start);
		start = end;
	}
	return (tokens[word_index] = NULL, tokens);
}
