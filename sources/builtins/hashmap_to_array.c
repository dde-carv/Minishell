/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:18:56 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/08 10:18:57 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sesh_var_array(char **array, unsigned int *j)
{
	unsigned int	i;
	t_entry			*current;
	t_entry			*tmp;

	i = 0;
	while (i < minis()->non_value_vars->size && \
		*j < (minis()->non_value_vars->count + minis()->env->count))
	{
		current = minis()->non_value_vars->entries[i];
		while (current)
		{
			tmp = current->next;
			array[*j] = ft_strjoin_var(1, current->key);
			current = tmp;
			(*j)++;
		}
		i++;
	}
}

static void	env_with_quotes_array(char **array, unsigned int *j)
{
	unsigned int	i;
	t_entry			*current;
	t_entry			*tmp;

	i = 0;
	while (i < minis()->env->size && *j < minis()->env->count)
	{
		current = minis()->env->entries[i];
		while (current)
		{
			tmp = current->next;
			array[*j] = ft_strjoin_var(5, current->key, "=", "\"",
					current->value, "\"");
			current = tmp;
			(*j)++;
		}
		i++;
	}
}

char	**hashmap_quotes_array_and_non_value_vars(void)
{
	unsigned int	j;
	char			**array;

	j = 0;
	array = (char **)ft_calloc(sizeof (char *),
			minis()->env->count + minis()->non_value_vars->count + 1);
	env_with_quotes_array(array, &j);
	sesh_var_array(array, &j);
	return (array);
}

char	**hashmap_to_array(void)
{
	unsigned int	i;
	unsigned int	j;
	t_entry			*current;
	t_entry			*tmp;
	char			**env;

	i = 0;
	j = 0;
	env = (char **)ft_calloc(sizeof (char *), minis()->env->count + 1);
	while (i < minis()->env->size && j < minis()->env->count)
	{
		current = minis()->env->entries[i];
		while (current)
		{
			tmp = current->next;
			env[j] = ft_strjoin_var(3, current->key, "=", current->value);
			current = tmp;
			j++;
		}
		i++;
	}
	return (env);
}
