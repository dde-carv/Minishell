
#include "minishell.h"

static void	set_first_var(char *str)
{
	char	**values;

	values = split_into2(str, '=');
	if (hashmap_search(minis()->env, values[0]))
	{
		hashmap_delete(minis()->env ,values[0]);
		insert_in_table(values[0], values[1], minis()->env);
		hashmap_delete(minis()->sesion_vars, values[0]);
		return ;
	}
	if (hashmap_search(minis()->sesion_vars, values[0]))
	{
		hashmap_delete(minis()->sesion_vars, values[0]);
		insert_in_table(values[0], values[1], minis()->sesion_vars);
	}
}

void	ft_sesh_vars(char *first, char **rest)
{
	int	i;

	i = 0;
	if (ft_strlen(first) == 1)
	{
		ft_exec_cmd(first, rest);
		return ;
	}
	set_first_var(first);
	set_rest_var(rest, &i); // TODO
}
