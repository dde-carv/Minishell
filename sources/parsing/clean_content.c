/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:25:15 by luiribei          #+#    #+#             */
/*   Updated: 2025/04/08 10:29:50 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	take_quotes(char **str)
{
	char	old_in_quotes;
	char	in_quotes;
	char	*s;
	int		i;
	int		j;

	s = *str;
	i = 0;
	j = 0;
	in_quotes = 0;
	while (s[i])
	{
		if ((s[i] == '"' || s[i] == '\''))
		{
			old_in_quotes = in_quotes;
			update_quote_state((*str)[i], &in_quotes);
			if (old_in_quotes == in_quotes)
				(*str)[j++] = s[i];
		}
		else
			(*str)[j++] = s[i];
		i++;
	}
	(*str)[j++] = '\0';
}

static void	process_cmd_tokens(t_input *lst)
{
	int		i;
	char	**tokens;

	tokens = split_value(lst->cmd);
	if (tokens && tokens[0])
	{
		free(lst->cmd);
		lst->cmd = ft_strdup(tokens[0]);
		if (tokens[1])
		{
			free(tokens[0]);
			i = -1;
			while (tokens[++i] && tokens[i + 1])
				tokens[i] = tokens[i + 1];
			tokens[i] = NULL;
		}
		else
		{
			free_array((void **)tokens);
			tokens = NULL;
		}
	}
	lst->args = tokens;
}

static void	take_expantions(t_input **lst)
{
	int		i;

	i = 0;
	take_quotes(&(*lst)->cmd);
	while (is_expantion((*lst)->cmd))
		(*lst)->cmd = sub_expantion((*lst)->cmd, get_value((*lst)->cmd));
	while (is_expantion((*lst)->arg))
		(*lst)->arg = sub_expantion((*lst)->arg, get_value((*lst)->arg));
	if (ft_strchr((*lst)->cmd, ' '))
		process_cmd_tokens(*lst);
	else if ((*lst)->arg)
		(*lst)->args = split_value((*lst)->arg);
	while ((*lst)->args && (*lst)->args[i])
	{
		take_quotes(&(*lst)->args[i]);
		i++;
	}
}

void	clean_content(void)
{
	t_input	*lst;

	lst = minis()->input;
	while (lst)
	{
		if (has_redirection(lst->cmd) || has_redirection(lst->arg))
			parse_redirects(&lst);
		expantions(&lst->cmd);
		expantions(&lst->arg);
		take_expantions(&lst);
		lst = lst->next;
	}
}
