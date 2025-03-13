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
	int		start;
	char	in_quotes;
	char	*new_str;
	char	*fname;

	i = -1;
	in_quotes = 0;
	start = 0;
	new_str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!new_str)
		exit(1);
	while (s[++i])
	{
		update_quote_state(s[i], &in_quotes);
		if ((s[i] == '<' || s[i] == '>') && !in_quotes)
		{
			type = get_redirection_type(s, &i);
			fname = extract_filename(s, &i);
			ft_fd_add_back(&cmd->fd, ft_fd_new(fname, -1, type));
			/* // skip over the redirection and filename
			while (start <= i)
				start++; */
		}
		else
			new_str[ft_strlen(new_str)] = s[i];
	}
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
	// ft_printf("-->%s<--\n", (*cmd)->cmd);
	if (has_redirection((*cmd)->cmd))
		parse_redirection(cmd, &(*cmd)->cmd); //, &(*cmd)->arg // ! if there is a redirect in the command search the arg for the first pos for the file name (Ex: "< lol cat"; cmd: "<" arg: "lol cat"; you want to parse "< lol")
	if (has_redirection((*cmd)->arg))
		parse_redirection(cmd, &(*cmd)->arg);
}

/* static void	parse_redirection(t_input **cmd, char **str)
{
	char	in_quotes;
	char	*new_str;
	char	*redir;
	t_type	type;
	int		new_str_len;
	int		start;
	int		i;

	i = 0;
	in_quotes = 0;
	new_str_len = ft_strlen(*str);
	new_str = ft_calloc(new_str_len + 1, sizeof(char));
	if (!new_str)
		exit(1);
	while ((*str)[i])
	{
		update_quote_state(*str[i], &in_quotes);
		if (((*str)[i] == '<' || (*str)[i] == '>') && !in_quotes)
		{
			start = i;
			if ((*str)[i] == '>' && (*str)[i + 1] == '>')
			{
				type = APPEND;
				i++;
			}
			else if ((*str)[i] == '<' && (*str)[i + 1] == '<')
			{
				type = HEREDOC;
				i++;
			}
			else if ((*str)[i] == '>')
				type = TRUNCATE;
			else
				type = REVERSE;
			i++;
			while ((*str)[i] == ' ')
				i++;
			start = i;
			while ((*str)[i] && (*str)[i] != ' '
				&& (*str)[i] != '<' && (*str)[i] != '>')
				i++;
			redir = ft_substr(*str, start, i - start);
			ft_fd_add_back(&(*cmd)->fd, ft_fd_new(redir, -1, type));
		}
		else
		{
			new_str[ft_strlen(new_str)] = (*str)[i];
			i++;
		}
	}
	free(*str);
	i = ft_strlen(new_str) - 1;
	while (i > 0 && new_str[i] == ' ')
		new_str[i--] = 0;
	*str = new_str;
} */
