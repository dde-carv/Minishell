#include "minishell.h"

t_env	*my_env(void)
{
	static t_env	data;

	return (&data);
}

t_minishell	*ms(void)
{
	static t_minishell	data;

	return (&data);
}
