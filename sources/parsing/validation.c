#include "../../includes/minishell.h"

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
		expantions(lst->cmd);
		expantions(lst->arg);
		lst = lst->next;
	}
	return (1);
}

bool	closed_quotes(char *str)
{
	int		i;
	char	in_quotes;

	i = 0;
	in_quotes = 0;
	if (!str)
		return (1);
	while (str[i++])
	{
		if ((str[i] == '"' || str[i] == '\'') && !in_quotes)
			in_quotes = str[i];
		else if (str[i] == in_quotes)
			in_quotes = 0;
	}
	return (in_quotes == 0);
}
