/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:25:27 by luiribei          #+#    #+#             */
/*   Updated: 2025/04/08 10:27:35 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cpy_input(t_entry *entry)
{
	t_input	*input;

	input = ft_input_lstnew(entry->key, entry->value);
	if (!input)
		exit(0);
	ft_input_lstadd_back(&minis()->input, input);
}

static char	*remove_spaces(char *str)
{
	int		start;
	int		end;
	char	*new_str;

	end = ft_strlen(str) - 1;
	start = 0;
	while (end > start && (str[end] == ' ' || str[end] == '\t'))
		end--;
	new_str = ft_substr(str, start, end - start + 1);
	free(str);
	return (new_str);
}

static char	*extract_arg(const char *str, int *i)
{
	char	in_quotes;
	char	*arg;
	int		start;

	in_quotes = 0;
	while (str[*i] == ' ' || str[*i] == '\t')
		(*i)++;
	start = *i;
	while (str[*i] && (str[*i] != '|' || in_quotes))
	{
		update_quote_state(str[*i], &in_quotes);
		(*i)++;
	}
	if (start == *i)
		return (ft_strdup(""));
	arg = remove_spaces(ft_substr(str, start, *i - start));
	return (arg);
}

static char	*extract_input(char *str, int *i)
{
	char	in_quotes;
	char	*cmd;
	int		start;

	in_quotes = 0;
	while (str[*i] == ' ' || str[*i] == '\t')
		(*i)++;
	start = *i;
	while (str[*i] && ((str[*i] != ' ' && str[*i] != '\t') || in_quotes) \
		&& (str[*i] != '|' || in_quotes))
	{
		update_quote_state(str[*i], &in_quotes);
		(*i)++;
	}
	if (start == *i)
		return (ft_strdup(""));
	cmd = ft_substr(str, start, *i - start);
	return (cmd);
}

void	parse_input(void)
{
	int		i;
	char	*cmd;
	char	*arg;
	t_entry	*entry;

	i = 0;
	while (minis()->ms->line[i])
	{
		cmd = extract_input(minis()->ms->line, &i);
		arg = extract_arg(minis()->ms->line, &i);
		entry = hash_action(minis()->table, (t_entry){cmd, arg, NULL}, ENTER);
		if (!entry)
			exit(0);
		if (minis()->ms->line[i] == '|')
			i++;
		cpy_input(entry);
		free_t_entry(entry);
		free(cmd);
		free(arg);
	}
	if (minis()->ms->line[i - 1] == '|')
		cpy_input(&(t_entry){"", "", NULL});
}
