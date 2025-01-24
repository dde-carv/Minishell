
#include "minishell.h"

static int	print_export(void)
{
	char	**export;

	export = hashmap_quotes_array_and_sesh_vars();
	//quick_sort_array(export, 0, ft_arraylen(export));
	ft_strjoin_to_array("declare -x", export);
	print_array_fd(export, 1);
	free_array(export);
}

static void	add_to_sesh_vars(char *arg)
{
	if (hashmap_search(minis()->env, arg))
		return ;
	if (hashmap_search(minis()->sesion_vars, arg))
		hashmap_delete(minis()->sesion_vars, arg);
	insert_in_table(arg, "NULL", minis()->sesion_vars);
}

static void	add_to_env(char *arg)
{
	char	**values;

	if (ft_strlen(arg) == 1)
		return ;
	values = split_into2(arg, '=');
	if (hashmap_search(minis()->sesion_vars, values[0]))
		hashmap_delete(minis()->sesion_vars, values[0]);
	if (hashmap_search(minis()->env, values[0]))
		hashmap_delete(minis()->env, values[0]);
	insert_in_table(values[0], values[1], minis()->env);
	free_array(values);
}

static int	add_var(char **args, int i)
{
	if (!args[i])
		return (0);
	if (ft_strchr(args[i], '='))
		add_to_env(args[i]);
	else
		add_to_sesh_vars(args[i]);
	return (add_var(args, i + 1));
}

int	ft_export(char **args)
{
	if (args[0])
		return(add_var(args, 0));
	else
		return(print_export());
}
