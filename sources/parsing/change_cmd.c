#include "minishell.h"

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

static void	new_cmd(t_input **cmd)
{
	t_input	*lst;

	lst = *cmd;
	free(lst->cmd);
	lst->cmd = ft_strdup(lst->args[0]);
	lst->args = new_args(lst->args);
}

void	change_cmd(t_input **cmd)
{
	t_input	*lst;

	lst = *cmd;
	while (lst)
	{
		new_cmd(&lst);
		lst = lst->next;
	}
}
