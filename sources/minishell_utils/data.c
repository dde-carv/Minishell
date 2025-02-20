#include "minishell.h"

/* t_global	*minis(void)
{
	static t_global	data;

	if(!data.ms)
	{
		data.ms = malloc(sizeof(t_minishell));
		if (!data.ms)
			return (NULL);
		ft_bzero(data.ms, sizeof(t_minishell));
	}
	if(!data.input)
	{
		data.input = malloc(sizeof(t_input));
		if (!data.input)
			return (NULL);
		ft_bzero(data.input, sizeof(t_input));
	}
	return (&data);
} */

t_global	*minis(void)
{
	static t_global		data;
	static t_minishell	ms;
	static t_hashmap	env;
	static t_hashmap	non_value_vars;

	if (!data.ms)
	{
		data.ms = &ms;
		data.input = NULL;
		data.env = &env;
		data.non_value_vars = &non_value_vars;
	}
	return (&data);
}