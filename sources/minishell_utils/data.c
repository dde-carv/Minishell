#include "minishell.h"

t_env	*my_env(void)
{
	static t_env	data;

	return (&data);
}

/* t_minishell	*ms(void)
{
	static t_minishell	data;

	return (&data);
} */

t_global	*minishell(void)
{
	static t_global	data;

	if(!data.ms)
	{
		data.ms = malloc(sizeof(t_minishell));
		if (!data.ms)
			error_mag(MALL_ERROR);
		ft_bzero(data.ms, sizeof(t_minishell));
	}
	if(!data.hash)
	{
		data.hash = malloc(sizeof(t_hashmap));
		if (!data.hash)
			error_mag(MALL_ERROR);
		ft_bzero(data.hash, sizeof(t_hashmap));
	}
	if(!data.my_env)
	{
		data.my_env = malloc(sizeof(t_env));
		if (!data.my_env)
			error_mag(MALL_ERROR);
		ft_bzero(data.my_env, sizeof(t_env));
	}
	return (&data);
}
