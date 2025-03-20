
#include "minishell.h"

static int	valid_var(char *str)
{
	if (!ft_isupper(*str) && !ft_islower(*str))
	{
		error_mess("export", INVALID_IDENTIFY, 1);
		return (0);
	}
	return (1);
}

static int	print_export(void)
{
	char	**export;

	export = hashmap_quotes_array_and_non_value_vars();
	quick_sort(export, 0, array_len(export));
	ft_strjoin_to_array("declare -x ", export);
	print_array_fd(export, 1);
	free_array((void **)export);
	return(0);
}

static void	add_to_non_value_vars(char *arg)
{
	if (hashmap_search(minis()->env, arg))
		return ;
	if (hashmap_search(minis()->non_value_vars, arg))
		hashmap_delete(minis()->non_value_vars, arg);
	insert_in_table(arg, "NULL", minis()->non_value_vars);
}

static void	add_to_env(char *arg)
{
	char	**values;

	if (ft_strlen(arg) == 1)
	{
		error_mess("export", SYNTAX_ERROR, 1);
		return ;
	}
	values = split_into2(arg, '=');
	if (hashmap_search(minis()->non_value_vars, values[0]))
		hashmap_delete(minis()->non_value_vars, values[0]);
	if (hashmap_search(minis()->env, values[0]))
		hashmap_delete(minis()->env, values[0]);
	insert_in_table(values[0], values[1], minis()->env);
	free_array((void **)values);
}

static int	add_var(char **args, int i)
{
	if (!args[i])
		return (0);
	if (!valid_var(args[i]))
		return (0);
	if (!ft_strchr(args[i], '=') && hashmap_search(minis()->env, args[i]))
		return (0);
	if (ft_strchr(args[i], '='))
		add_to_env(args[i]);
	else
		add_to_non_value_vars(args[i]);
	return (add_var(args, i + 1));
}

int	ft_export(char **args)
{
	minis()->error_status = 0;
	if (args[0])
		return(add_var(args, 0));
	else
		return(print_export());
}
