#include "minishell.h"

static t_type	get_redirection_type(const char *str, int *i)
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

static void	handle_redirection(t_input *cmd, const char *s, int *i)
{
	t_type	type;
	char	*fname;
	char	*tmp;
	int		start;
	int		len;
	char	quote;

	type = get_redirection_type(s, i);
	if (s[*i] == '>' || s[*i] == '<')
		(*i)++;
	while (s[*i] && (s[*i] == ' ' || s[*i] == '\t'))
		(*i)++;
	if (!s[*i] || s[*i] == '<' || s[*i] == '>')
	{
		error_mess("minishell", "syntax error", 2);
		*i = ft_strlen(s);
		return;
	}
	if (s[*i] == '\'' || s[*i] == '"')
	{
		quote = s[*i];
		(*i)++; // skip the starting quote
		start = *i;
		while (s[*i] && s[*i] != quote)
			(*i)++;
		len = *i - start;
		// extract including quotes so that remove_all_quotes works consistently
		fname = ft_substr(s, start - 1, len + 2);
		if (s[*i] == quote)
			(*i)++; // consume the closing quote
	}
	else
	{
		start = *i;
		while (s[*i] && s[*i] != ' ' && s[*i] != '<' && s[*i] != '>')
			(*i)++;
		len = *i - start;
		fname = ft_substr(s, start, len);
	}
	// For HEREDOC redirection, do not expand the delimiter.
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
		// Optionally, remove quotes if present for consistency.
		tmp = remove_all_quotes(fname);
		free(fname);
		fname = tmp;
	}
	ft_fd_add_back(&cmd->fd, ft_fd_new(fname, -1, type));
	while (s[*i] && (s[*i] == ' ' || s[*i] == '\t'))
		(*i)++;
	(*i)--;
}

static char	*build_new_str(t_input *cmd, const char *s)
{
	int		i;
	int		pos;
	char	in_quotes;
	char	*new_str;

	i = -1;
	pos = 0;
	in_quotes = 0;
	new_str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!new_str)
		exit(1);
	while (s[++i])
	{
		update_quote_state(s[i], &in_quotes);
		if ((s[i] == '<' || s[i] == '>') && !in_quotes)
		{
			handle_redirection(cmd, s, &i);
			if (minis()->error_status != 0)
			{
				free(new_str);
				return (ft_strdup("")); // abort building the string
			}
		}
		else
		{
			update_quote_state(s[i], &in_quotes);
			new_str[pos++] = s[i];
		}
	}
	new_str[pos] = '\0';
	return (new_str);
}

void	parse_redirection(t_input **cmd, char **str)
{
	int		i;
	char	*new_str;

	new_str = build_new_str(*cmd, *str);
	free(*str);
	i = ft_strlen(new_str) - 1;
	while (i > 0 && (new_str[i] == ' ' || new_str[i] == '\t'))
	{
		new_str[i] = 0;
		i--;
	}
	*str = new_str;
}

void	parse_redirects(t_input **cmd)
{
	char	*combined_str;
	char	*processed_str;
	//char	*space_pos;
	char	*trimmed;

	combined_str = ft_strjoin_var(3, (*cmd)->cmd, " ", (*cmd)->arg);
	processed_str = build_new_str(*cmd, combined_str);
	free(combined_str);
	trimmed = ft_strtrim(processed_str, " ");
	free(processed_str);
	processed_str = trimmed;
	//space_pos = ft_strchr(processed_str, ' ');
	update_cmd_args(cmd, processed_str);
	free(processed_str);
}
