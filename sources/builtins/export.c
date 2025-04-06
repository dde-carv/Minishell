
#include "minishell.h"

static int	matrix_len(char **matrix)
{
	int	i;

	i = 0;
	if (*matrix)
	{
		while (matrix[i + 1])
			i++;
	}
	return (i);
}

static int	valid_var(char *str)
{
	int		i;
	char	*full_mess;

	if (!ft_isupper(*str) && !ft_islower(*str))
	{
		full_mess = ft_strjoin("export: ", str);
		error_mess(full_mess, INVALID_IDENTIFY, 1);
		free_pointer(full_mess);
		return (0);
	}
	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
		{
			full_mess = ft_strjoin("export: ", str);
			error_mess(full_mess, INVALID_IDENTIFY, 1);
			free_pointer(full_mess);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	print_export(int fd)
{
	char	**export;

	export = hashmap_quotes_array_and_non_value_vars();
	quick_sort(export, 0, matrix_len(export));
	ft_strjoin_to_array("declare -x ", export);
	print_array_fd(export, fd);
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
		return (add_var(args, i + 1));
	if (!ft_strchr(args[i], '=') && hashmap_search(minis()->env, args[i]))
		return (0);
	if (ft_strchr(args[i], '='))
		add_to_env(args[i]);
	else
		add_to_non_value_vars(args[i]);
	return (add_var(args, i + 1));
}

int	ft_export(char **args, int fd)
{
	minis()->error_status = 0;
	if (args[0])
		return(add_var(args, 0));
	else
		return(print_export(fd));
}
