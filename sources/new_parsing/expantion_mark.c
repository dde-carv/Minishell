/* #include "minishell.h"

static void	helper(t_fd **f, char *name, int *index)
{
	int	i;

	i = *index;
	if (name[i] == '>' && name[i + 1] == '>')
	{
		(*f)->type = APPEND;
		i++;
	}
	else if (name[i] == '<' && name[i + 1] == '<')
	{
		(*f)->type = HEREDOC;
		i++;
	}
	else if (name[i] == '<' && name[i + 1] == '<')
	{
		(*f)->type = HEREDOC;
		i++;
	}
	else if (name[i] == '>')
		(*f)->type = TRUNCATE;
	else
		(*f)->type = REVERSE;
	i++;
	*index = i;
}

static int	get_type(t_fd **f, char *name)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (name[++i])
	{
		if ((name[i] == '"' || name[i] == '\'') && !c)
			c = name[i];
		else if (name[i] == c)
			c = 0;
		else if (!c && (name[i] == '<' || name[i] == '>'))
		{
			helper(f, name, &i);
			while (name[i] == ' ')
				i++;
			break ;
		}
	}
	return (i);
}

static void	file_name_clean(t_fd **f, char **name)
{
	char	*s;
	int		i;

	i = get_type(f, *name);
	s = ft_substr(*name, i, ft_strlen(*name) - i);
	free(*name);
	*name = s;
}

static void	fd_expantions(t_fd **f)
{
	t_fd	*f_d;

	if (!*f)
		return ;
	f_d = *f;
	while (f_d)
	{
		file_name_clean(&f_d, &f_d->file_n);
		expantions(&(f_d)->file_n);
		while (is_expantion((f_d)->file_n))
			(f_d)->file_n = sub_expantion((f_d)->file_n, get_value((*f)->file_n));
		take_quotes(&f_d->file_n);
		f_d = f_d->next;
	}
}

void	expantion_mark(void)
{
	t_input	*lst;

	lst = minis()->input;
	while (lst)
	{
		create_args(&lst);
		fd_expantions(&lst->fd);
		lst = lst->next;
	}
	execute();
}
 */