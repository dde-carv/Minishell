#include "../../includes/minishell.h"

static void	take_spaces(t_string *s)
{
	int	i;

	i = ft_strlen(*s) - 1;
	if (i == -1)
		return ;
	while (i && (*s)[i] == ' ')
		(*s)[i--] = 0;
}

void	take_quotes(t_string *str)
{
	t_string	s;
	int			i;
	int			y;
	int			c;

	s = *str;
	i = -1;
	y = -1;
	c = 0;
	while (s[++i])
	{
		if ((s[i] == '"' || s[i] == '\'') && !c)
			c = s[i];
		else if (s[i] == c)
			c = 0;
		else
			(*str)[++y] = s[i];
	}
	while (y < i)
		(*str)[++y] = 0;
}

static void	take_expantions(t_cmd **lst)
{
	bool	f;
	int		i;

	i = -1;
	f = split_need((*lst)->cmd);
	take_quotes(&(*lst)->cmd);
	while (is_expantion((*lst)->cmd))
		(*lst)->cmd = sub_expantion((*lst)->cmd, get_var((*lst)->cmd));
	while (is_expantion((*lst)->arg))
		(*lst)->arg = sub_expantion((*lst)->arg, get_var((*lst)->arg));
	if (f && *(*lst)->cmd)
		matrix(lst);
	else
		(*lst)->matrix = split_value((*lst)->arg);
	while ((*lst)->matrix && (*lst)->matrix[++i] != NULL)
	{
		take_quotes(&(*lst)->matrix[i]);
		take_spaces(&(*lst)->matrix[i]);
	}
}
