#include "../../includes/minishell.h"

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
	char	*s;
	int		i;
	int		j;
	int		in_quotes;

	s = *str;
	i = 0;
	j = 0;
	in_quotes = 0;
	while (s[i++])
	{
		if ((s[i] == '"' || s[i] == '\'') && !in_quotes)
			in_quotes = s[i];
		else if (s[i] == in_quotes)
			in_quotes = 0;
		else
			(*str)[j++] = s[i];
	}
	while (j < i)
		(*str)[j++] = 0;
}

static void	take_expantions(t_input **lst)
{
	bool	f;
	int		i;

	i = 0;
	f = split_need((*lst)->cmd);
	take_quotes(&(*lst)->cmd);
	while (is_expantion((*lst)->cmd))
		(*lst)->cmd = sub_expantion((*lst)->cmd, get_var((*lst)->cmd));
	while (is_expantion((*lst)->arg))
		(*lst)->arg = sub_expantion((*lst)->arg, get_var((*lst)->arg));
	if (f && *(*lst)->cmd)
		args(lst);
	else
		(*lst)->args = split_value((*lst)->arg);
	while ((*lst)->args && (*lst)->args[i++] != NULL)
	{
		take_quotes(&(*lst)->args[i]);
		take_spaces(&(*lst)->args[i]);
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
