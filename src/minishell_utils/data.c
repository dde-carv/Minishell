#include "minishell.h"

t_env	*my_env(void)
{
	static t_env	data;

	if (!data.var_n)
		ft_bzero(&data, sizeof(data));
	return (&data);
}

t_minishell	*ms(void)
{
	static t_minishell	data;

	return (&data);
}
