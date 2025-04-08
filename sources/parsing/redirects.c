/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:25:34 by luiribei          #+#    #+#             */
/*   Updated: 2025/04/08 17:45:38 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	process_and_add_redirection(t_input *cmd,
	const char *s, int *i, t_type type)
{
	char	*fname;
	char	*tmp;

	fname = extract_filename(s, i);
	if (type != HEREDOC)
	{
		expantions(&fname);
		tmp = remove_all_quotes(fname);
		free(fname);
		fname = tmp;
		while (is_expantion(fname))
			fname = sub_expantion(fname, get_value(fname));
	}
	else
	{
		tmp = remove_all_quotes(fname);
		free(fname);
		fname = tmp;
	}
	ft_fd_add_back(&cmd->fd, ft_fd_new(fname, -1, type));
	while (s[*i] && (s[*i] == ' ' || s[*i] == '\t'))
		(*i)++;
	(*i)--;
}

static void	handle_redirection(t_input *cmd, const char *s, int *i)
{
	t_type	type;

	type = get_redirection_type(s, i);
	if (s[*i] == '>' || s[*i] == '<')
		(*i)++;
	while (s[*i] && (s[*i] == ' ' || s[*i] == '\t'))
		(*i)++;
	if (!s[*i] || s[*i] == '<' || s[*i] == '>')
	{
		error_mess("minishell", "syntax error", 2);
		*i = ft_strlen(s);
		return ;
	}
	process_and_add_redirection(cmd, s, i, type);
}

static int	process_char(t_input *cmd, const char *s, int *i, t_help *b)
{
	if ((s[*i] == '<' || s[*i] == '>') && !b->in_quotes)
	{
		handle_redirection(cmd, s, i);
		if (minis()->error_status != 0)
			return (1);
	}
	else
	{
		update_quote_state(s[*i], &b->in_quotes);
		b->new_str[b->pos++] = s[*i];
	}
	return (0);
}

static char	*build_new_str(t_input *cmd, const char *s)
{
	int		i;
	t_help	b;

	i = 0;
	b.pos = 0;
	b.in_quotes = 0;
	b.new_str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!b.new_str)
		return (NULL);
	while (s[i])
	{
		if (process_char(cmd, s, &i, &b))
		{
			free(b.new_str);
			return (ft_strdup(""));
		}
		i++;
	}
	b.new_str[b.pos] = '\0';
	return (b.new_str);
}

void	parse_redirects(t_input **cmd)
{
	char	*combined_str;
	char	*processed_str;
	char	*trimmed;

	combined_str = ft_strjoin_var(3, (*cmd)->cmd, " ", (*cmd)->arg);
	processed_str = build_new_str(*cmd, combined_str);
	free(combined_str);
	trimmed = ft_strtrim(processed_str, " ");
	free(processed_str);
	processed_str = trimmed;
	update_cmd_args(cmd, processed_str);
	free(processed_str);
}
