/* #include "minishell.h"

static void	mark_pipes(void)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (minis()->ms->line[++i])
	{
		if ((minis()->ms->line[i] == '\'' || minis()->ms->line[i] == '"') && !c)
			c = minis()->ms->line[i];
		else if (c == minis()->ms->line[i])
			c = 0;
		else if (minis()->ms->line[i] == '|' && !c)
			minis()->ms->line[i] = 2;
	}
}

static int	count_pipes(void)
{
	int	i;
	int	pipes;

	i = -1;
	pipes = 0;
	while (minis()->ms->line[++i])
	{
		if (minis()->ms->line[i] == 2)
			pipes++;
	}
	return (pipes);
}

static bool	check_errors(char **s)
{
	int	i;

	if (array_len(s) == 1 && !*s[0])
		return (free_array((void **)s), true);
	i = -1;
	while (s[++i])
	{
		if (!*s[i])
			return (\
			ft_putendl_fd("bash: syntax error near unexpected token `|'", 2),
			free_array((void **)s), true);
	}
	return (false);
}

void	new_parse(void)
{
	char	**s;
	int		i;

	i = -1;
	if (!minis()->ms->line || !*minis()->ms->line
		|| !closed_quotes(minis()->ms->line))
		return ;
	mark_pipes();
	s = ft_split(minis()->ms->line, 2);
	ft_printf("-> FODASE <-");
	if (array_len(s) < count_pipes())
		return (ft_putendl_fd("bash: syntax error near unexpected token `|'", 2), free_array((void **)s));
	while (s[++i])
	{
		trim_spaces(&s[i]);
		trim_front_spaces(&s[i]);
	}
	if (check_errors(s))
		return ;
	minis()->input->args = s;
	args_to_cmd();
}
 */