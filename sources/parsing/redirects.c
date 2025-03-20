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

static char	*extract_filename(const char *s, int *i)
{
	int		start;
	int		len;
	char	*fname;

	while (s[*i] && (s[*i] == ' '
		|| s[*i] == '<' || s[*i] == '>'))
		(*i)++;
	start = *i;
	while (s[*i] && s[*i] != ' '
		&& s[*i] != '<' && s[*i] != '>')
		(*i)++;
	len = *i - start;
	fname = ft_substr(s, start, len);
	return (fname);
}

static char	*build_new_str(t_input *cmd, const char *s)
{
	t_type	type;
	int		i;
	char	in_quotes;
	char	*new_str;
	char	*fname;

	i = -1;
	in_quotes = 0;
	new_str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!new_str)
		exit(1);
	while (s[++i])
	{
		ft_printf("<-- %c -->", s[i]);
		update_quote_state(s[i], &in_quotes);
		if ((s[i] == '<' || s[i] == '>') && !in_quotes)
		{
			type = get_redirection_type(s, &i);
			fname = extract_filename(s, &i);
			ft_fd_add_back(&cmd->fd, ft_fd_new(fname, -1, type));
			//free(fname);
		}
		else
			new_str[ft_strlen(new_str)] = s[i];
	}
	new_str[ft_strlen(new_str)] = '\0';
	return (new_str);
}

void	parse_redirection(t_input **cmd, char **str)
{
	int		i;
	char	*new_str;

	new_str = build_new_str(*cmd, *str);
	free(*str);
	i = ft_strlen(new_str) - 1;
	while (i > 0 && new_str[i] == ' ')
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
	char	*space_pos;

	combined_str = ft_strjoin_var(3, (*cmd)->cmd, " ", (*cmd)->arg);
	processed_str = build_new_str(*cmd, combined_str);
	free(combined_str);
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
	free(processed_str);
}
