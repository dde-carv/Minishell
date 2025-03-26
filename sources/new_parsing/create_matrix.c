#include "minishell.h"

static void	mark_spaces(char **s)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while ((*s)[++i])
	{
		if (((*s)[i] == '"' || (*s)[i] == '\'') && !c)
			c = (*s)[i];
		else if ((*s)[i] == c)
			c = 0;
		else if ((*s)[i] == ' ' && !c)
			(*s)[i] = 2;
	}
}

void	create_args(t_input **cmd)
{
	int	i;

	i = -1;
	expantions(&(*cmd)->arg);
	while (is_expantion((*cmd)->arg))
		(*cmd)->arg = sub_expantion((*cmd)->arg, get_value((*cmd)->arg));
	mark_spaces(&(*cmd)->arg);
	(*cmd)->args = ft_split((*cmd)->arg, 2);
	if (!(*cmd)->args)
		return ;
	while ((*cmd)->args[++i])
		take_quotes(&(*cmd)->args[i]);
}
