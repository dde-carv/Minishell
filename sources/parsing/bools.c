#include "minishell.h"

void	update_quote_state(char c, char *in_quotes)
{
	if ((c == '"' || c == '\'') && !(*in_quotes))
		*in_quotes = c;
	else if (c == *in_quotes)
		*in_quotes = 0;
}

bool	is_valid(void)
{
	t_input	*lst;

	lst = minis()->input;
	while (lst)
	{
		if (!closed_quotes(lst->cmd) || !closed_quotes(lst->arg))
		{
			error_mess("minishell", SYNTAX_ERROR, 1);
			return (0);
		}
		if (!lst->cmd || !*lst->cmd)
		{
			error_mess("minishell", SYNTAX_ERROR, 1);
			return (0);
		}
		lst = lst->next;
	}
	return (1);
}

bool	closed_quotes(char *str)
{
	char	in_quotes;
	int		i;

	i = -1;
	in_quotes = 0;
	if (!str)
		return (1);
	while (str[++i])
		update_quote_state(str[i], &in_quotes);
	if (in_quotes)
		ft_putendl_fd("error open quotes", 2);
	return (in_quotes == 0);
}

bool	is_expantion(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == 2)
			return (1);
		str++;
	}
	return (0);
}

bool	has_redirection(char *s)
{
	int		i;
	char	in_quotes;

	i = 0;
	in_quotes = 0;
	while (s[i])
	{
		update_quote_state(s[i], &in_quotes);
		if ((s[i] == '<' || s[i] == '>') && !in_quotes)
			return (true);
		i++;
	}
	return (false);
}

/* bool	needs_split(char *s)
{
	char	in_quotes;
	int		i;

	i = 0;
	if (!s || !*s || *s != 2)
		return (false);
	in_quotes = 0;
	while (s[i++])
	{
		update_quote_state(s[i], &in_quotes);
		if (s[i] == 2 && !in_quotes)
		{
			while (ft_isalpha(s[++i]))
				;
			if (s[i] == 0 || s[i] == ' ')
				return (true);
			return (false);
		}
	}
	return (false);
} */
