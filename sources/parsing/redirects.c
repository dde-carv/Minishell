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
	int		start;
	int		len;

	type = get_redirection_type(s, i);
	while (s[*i] && (s[*i] == ' ' || s[*i] == '<' || s[*i] == '>'))
		(*i)++;
	start = *i;
	while (s[*i] && s[*i] != ' ' && s[*i] != '<' && s[*i] != '>')
		(*i)++;
	len = *i - start;
	fname = ft_substr(s, start, len);
	ft_fd_add_back(&cmd->fd, ft_fd_new(fname, -1, type));
	while (s[*i] && s[*i] == ' ')
		(*i)++;
	(*i)--;
}

static char	*build_new_str(t_input *cmd, const char *s)
{
	int		i;
	char	in_quotes;
	char	*new_str;

	i = -1;
	in_quotes = 0;
	new_str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!new_str)
		exit(1);
	while (s[++i])
	{
		update_quote_state(s[i], &in_quotes);
		if ((s[i] == '<' || s[i] == '>') && !in_quotes)
			handle_redirection(cmd, s, &i);
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
