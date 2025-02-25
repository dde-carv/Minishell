#include "minishell.h"

void	update_quote_state(char c, char *in_quotes)
{
	if ((c == '"' || c == '\'') && !(*in_quotes))
		*in_quotes = c;
	else if (c == *in_quotes)
		*in_quotes = 0;
}

static void	take_spaces(char **s)
{
	int	i;

	i = ft_strlen(*s) - 1;
	if (i == -1)
		return ;
	while (i && (*s)[i] == ' ')
		(*s)[i--] = 0;
}

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

static void	take_expantions(t_input **lst)
{
	bool	f;
	int		i;

	i = 0;
	f = needs_split((*lst)->cmd);
	take_quotes(&(*lst)->cmd);
	while (is_expantion((*lst)->cmd))
		(*lst)->cmd = sub_expantion((*lst)->cmd, get_value((*lst)->cmd));
	while (is_expantion((*lst)->arg))
		(*lst)->arg = sub_expantion((*lst)->arg, get_value((*lst)->arg));
	if (f && *(*lst)->cmd)
		args(lst);
	else
		(*lst)->args = split_value((*lst)->arg);
	while ((*lst)->args && (*lst)->args[i])
	{
		take_quotes(&(*lst)->args[i]);
		take_spaces(&(*lst)->args[i]);
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
