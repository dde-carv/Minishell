
#include "minishell.h"

static void	set_rest_vars(char **strs, int i)
{
	char **values;

	if (!strs[i])
		return ;
	values = split_into2(strs[i], '=');
	if (hashmap_search(minis()->non_value_vars, values[0]))
	{
		hashmap_delete(minis()->non_value_vars ,values[0]);
		insert_in_table(values[0], values[1], minis()->env);
	}
	if (hashmap_search(minis()->env, values[0]))
	{
		hashmap_delete(minis()->env ,values[0]);
		insert_in_table(values[0], values[1], minis()->env);
		if (hashmap_search(minis()->sesion_vars, values[0]))
			hashmap_delete(minis()->sesion_vars, values[0]);
		free_array(values);
		return ;
	}
	if (hashmap_search(minis()->sesion_vars, values[0]))
		hashmap_delete(minis()->sesion_vars, values[0]);
	insert_in_table(values[0], values[1], minis()->sesion_vars);
	free_array(values);
	set_rest_vars(strs, i + 1);
}

static void	set_first_var(char *str)
{
	char	**values;

	values = split_into2(str, '=');
	if (hashmap_search(minis()->non_value_vars, values[0]))
	{
		hashmap_delete(minis()->non_value_vars ,values[0]);
		insert_in_table(values[0], values[1], minis()->env);
	}
	if (hashmap_search(minis()->env, values[0]))
	{
		hashmap_delete(minis()->env ,values[0]);
		insert_in_table(values[0], values[1], minis()->env);
		if (hashmap_search(minis()->sesion_vars, values[0]))
			hashmap_delete(minis()->sesion_vars, values[0]);
		free_array(values);
		return ;
	}
	if (hashmap_search(minis()->sesion_vars, values[0]))
		hashmap_delete(minis()->sesion_vars, values[0]);
	insert_in_table(values[0], values[1], minis()->sesion_vars);
	free_array(values);
}

void	ft_sesh_vars(char *first, char **rest)
{
/* 	if (ft_strlen(first) == 1)
	{
		ft_exec_cmd(first, rest);
		return ;
	} */
	set_first_var(first);
	set_rest_vars(rest, 0);
}
