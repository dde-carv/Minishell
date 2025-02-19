/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:38:31 by luiribei          #+#    #+#             */
/*   Updated: 2025/02/19 10:03:51 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
	while (end > start && str[end] == ' ')
		end--;
	new_str = ft_substr(str, start, end - start + 1);
	free(str);
	return (new_str);
}

/**
 * Extracts a command from the input starting at index *i.
 * Updates *i to the position after the command.
 */
static char	*extract_arg(const char *str, int *i)
{
	int		start;
	int		in_quotes;
	char	*arg;

	in_quotes = 0;
	while (str[*i] == ' ')
		(*i)++;
	start = *i;
	while (str[*i] && (str[*i] != '|' || in_quotes))
	{
		if ((str[*i] == '\'' || str[*i] == '"') && !in_quotes)
			in_quotes = str[*i];
		else if (in_quotes == str[*i])
			in_quotes = 0;
		(*i)++;
	}
	if (start == *i)
		return (ft_strdup(""));
	arg = remove_spaces(ft_substr(str, start, *i - start));
	return (arg);
}

	/* // Remove surrounding quotes if present
	if ((arg[0] == '\'' && arg[ft_strlen(arg) - 1] == '\'') ||
		(arg[0] == '"' && arg[ft_strlen(arg) - 1] == '"'))
	{
		char *temp = ft_substr(arg, 1, ft_strlen(arg) - 2);
		free(arg);
		arg = temp;
	} */

/**
 * Extracts an argument from the input starting at index *i.
 * Updates *i to the position after the argument.
 */
static char	*extract_cmd(char *str, int *i)
{
	char	*cmd;
	int		start;
	int		in_quotes;

	in_quotes = 0;
	while (str[*i] == ' ')
		(*i)++;
	start = *i;
	while (str[*i] && (str[*i] != ' ' || in_quotes) \
		&& (str[*i] != '|' || in_quotes))
	{
		if ((str[*i] == '\'' || str[*i] == '"') && !in_quotes)
			in_quotes = str[*i];
		else if (in_quotes == str[*i])
			in_quotes = 0;
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
	t_entry	e;

	i = 0;
	while (minis()->ms->line[i])
	{
		cmd = extract_cmd(minis()->ms->line, &i);
		arg = extract_arg(minis()->ms->line, &i);
		entry = hash_action(minis()->table, (t_entry){cmd, arg, NULL}, ENTER);
		if (!entry)
			exit(0);
		if (minis()->ms->line[i] == '|')
			i++;
		cpy_input(entry);
		free_t_entry(entry);// ! Posible Invalid free because of parsing and expantions(in hugo's transform_str.c clean_content function)
		free(cmd);
		free(arg);
	}
	if (minis()->ms->line[i - 1] == '|')
	{
		e.key = "";
		e.value = "";
		cpy_input(&e);
	}
}
