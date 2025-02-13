#include "../../includes/minishell.h"

static void	add_args(t_input **lst, char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[++i])
		;
	(*lst)->args = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	j = 0;
	while (s[++i])
		(*lst)->args[j++] = ft_strdup(s[i]);
	(*lst)->args[j++] = NULL;
}

static void	join_args(t_input **lst, char **s)
{
	char	**str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while ((*lst)->args[++i])
		;
	while (s[++j])
		;
	str = ft_calloc(i + j + 1, sizeof(char *));
	str[i] = NULL;
	i = -1;
	while ((*lst)->args[++i])
		str[i] = ft_strdup((*lst)->args[i]);
	j = -1;
	while (s[++j])
		str[i++] = ft_strdup(s[j]);
	free_args(s);
	free_args((*lst)->args);
	(*lst)->args = str;
}

void	args(t_input **lst)
{
	char	**s;
	int		i;

	s = split_value((*lst)->cmd);
	free((*lst)->cmd);
	(*lst)->cmd = ft_strdup(s[0]);
	add_args(lst, s);
	i = 0;
	while (s[i++])
		free(s[i]);
	free(s[i]);
	free(s);
	join_args(lst, split_value((*lst)->arg));
}