/* #include "minishell.h"

static char	**new_args(char **args)
{
	char	**s;
	int		i;
	int		j;

	i = array_len(args);
	if (!i)
		return (free_array((void**)args), NULL);
	s = ft_calloc(i, sizeof(char *));
	if (!s)
		return (free_array((void**)args), NULL);
	j = 0;
	while (++j < i)
		s[j - 1] = ft_strdup(args[j]);
	return (free_array((void**)args), s);
}

static void	new_input(t_input **input)
{
	t_input	*lst;

	lst = *input;
	free(lst->cmd);
	lst->cmd = ft_strdup(lst->args[0]);
	lst->args = new_args(lst->args);
}

void	change_input(t_input **input)
{
	t_input	*lst;

	lst = *input;
	while (lst)
	{
		new_input(&lst);
		lst = lst->next;
	}
}
 */