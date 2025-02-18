#include "../../includes/minishell.h"

bool	has_redirection(char *s)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if ((s[i] == '"' || s[i] == '\'') && !c)
			c = s[i];
		else if (s[i] == c)
			c = 0;
		else if (!c && (s[i] == '<' || s[i] == '>'))
			return (true);
		i++;
	}
	return (false);
}

static void parse_redirection(t_input **cmd, char **str)
{
	int i;
	int start;
	int c;
	t_type type;
	char *redir;
	char *new_str;
	int new_str_len;

	i = 0;
	c = 0;
	new_str_len = ft_strlen(*str);
	new_str = ft_calloc(new_str_len + 1, sizeof(char));
	if (!new_str)
		exit(1);
	while ((*str)[i])
	{
		if (((*str)[i] == '"' || (*str)[i] == '\'') && !c)
			c = (*str)[i];
		else if ((*str)[i] == c)
			c = 0;
		else if (!c && ((*str)[i] == '<' || (*str)[i] == '>')) {
			start = i;
			if ((*str)[i] == '>' && (*str)[i + 1] == '>')
			{
				type = APPEND;
				i++;
			}
			else if ((*str)[i] == '<' && (*str)[i + 1] == '<') {
				type = HEREDOC;
				i++;
			}
			else if ((*str)[i] == '>')
				type = CREATE;
			else
				type = REVERSE;
			i++;
			while ((*str)[i] == ' ')
				i++;
			start = i;
			while ((*str)[i] && (*str)[i] != ' ' && (*str)[i] != '<' && (*str)[i] != '>')
				i++;
			redir = ft_substr(*str, start, i - start);
			ft_fdadd_back(&(*cmd)->fd, ft_fd_new(redir, -1, type));
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
}

void	parse_redirects(t_input **cmd)
{
	if (has_redirection((*cmd)->cmd))
		parse_redirection(cmd, &(*cmd)->cmd);
	if (has_redirection((*cmd)->arg))
		parse_redirection(cmd, &(*cmd)->arg);
}
