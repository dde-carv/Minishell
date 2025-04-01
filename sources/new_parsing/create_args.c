/* #include "minishell.h"

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

void	create_args(t_input **input)
{
	int	i;

	i = -1;
	expantions(&(*input)->arg);
	while (is_expantion((*input)->arg))
		(*input)->arg = sub_expantion((*input)->arg, get_value((*input)->arg));
	mark_spaces(&(*input)->arg);
	(*input)->args = ft_split((*input)->arg, 2);
	if (!(*input)->args)
		return ;
	while ((*input)->args[++i])
		take_quotes(&(*input)->args[i]);
}
 */