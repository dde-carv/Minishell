/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:18:49 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/08 10:18:50 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	add_var(char **args, int i)
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
