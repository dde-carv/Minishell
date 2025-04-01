/* #include "minishell.h"

static int	start_redirect(char *s)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (s[++i])
	{
		if ((s[i] == '\'' || s[i] == '"') && !c)
			c = s[i];
		else if (s[i] == c)
			c = 0;
		else if ((s[i] == '>' || s[i] == '<') && !c)
			break ;
	}
	return (i);
}

static int	end_redirect(char *s, int start)
{
	int	i;
	int	c;

	i = start + 1;
	c = 0;
	if (s[i] == '>' || s[i] == '<')
		i++;
	while (s[i] == ' ')
		i++;
	if (s[i] == '>' || s[i] == '<' || !s[i])
		return (i);
	while (s[i])
	{
		if ((s[i] == '"' || s[i] == '\'') && !c)
			c = s[i];
		else if (s[i] == c)
			c = 0;
		if (s[i] == ' ' && !c)
			break ;
		i++;
	}
	return (i);
}

static t_fd	*take_red(char **s)
{
	t_fd	*f;
	int		i;
	int		j;

	f = ft_calloc(sizeof(t_fd), 1);
	if (!f)
		return (NULL);
	i = start_redirect(*s);
	j = end_redirect(*s, i);
	f->file_n = ft_substr(*s, i, j - i);
	*s = new_cut(s, i, j);
	return (f);
}

static void	take_redirect(t_input **cmd)
{
	while (has_redirection((*cmd)->arg))
		ft_fd_add_back(&(*cmd)->fd, take_red(&(*cmd)->arg));
}

void	redirects_parsing(void)
{
	t_input	*input;

	input = minis()->input;
	while (input)
	{
		take_redirect(&input);
		input = input->next;
	}
	expantion_mark();
}
 */