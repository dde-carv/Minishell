
#include "minishell.h"

void	create_var(char *var_n, char *var_v, int flag_mall)
{
	t_env	**tmp;
	t_env	*new_var;

	new_var = malloc(sizeof(t_env));
	if (!new_var)
		env_fail(MALL_ERROR, var_n, var_v, flag_mall);
	

}
