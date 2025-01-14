
#include "minishell.h"

char	*get_var(char *varn)
{
	t_env	*tmp;

	tmp = minis()->my_env;
	while (tmp->next)
	{
		if (ft_strcmp(varn, tmp->var_n))
			break ;
		tmp = tmp->next;
	}
	ft_printf("%s=%s\n", tmp->var_n, tmp->var_v); //For test purpose
	return (tmp->var_v);
}

void	env_fail(int flag, char *var_n, char *var_v, int flag_mall)
{
	(void)flag;
	if (flag_mall == YES_MALL)
	{
		free(var_n);
		free(var_v);
	}
	else if (flag_mall == NY_MALL)
		free(var_v);
	//error_mag(flag);
}

/* void	create_var(char *var_n, char *var_v, int flag_mall)
{
	t_env *tmp;
	t_env *new_var;

	new_var = malloc(sizeof(t_env));
	if (!new_var)
		env_fail(MALL_ERROR, var_n, var_v, flag_mall);
	tmp = minis()->my_env;
	if (!tmp->var_n && !tmp->var_v)
	{
		tmp->var_n = ft_strdup(var_n);
		tmp->var_v = ft_strdup(var_v);
		tmp->next = NULL;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_var;
	new_var->var_n = ft_strdup(var_n);
	new_var->var_v = ft_strdup(var_v);
	new_var->next = NULL;
	if (!new_var->var_n || !new_var->var_v)
		env_fail(MALL_ERROR, var_n, var_v, flag_mall);
} */

void	create_var(char *var_n, char *var_v, int flag_mall)
{
	t_env *tmp;
	t_env *new_var;

	new_var = malloc(sizeof(t_env));
	if (!new_var)
		env_fail(MALL_ERROR, var_n, var_v, flag_mall);
	tmp = minis()->my_env;
	if (!tmp->var_n && !tmp->var_v)
	{
		tmp->var_n = ft_strdup(var_n);
		tmp->var_v = ft_strdup(var_v);
		if (!tmp->var_n || !tmp->var_v)
			env_fail(MALL_ERROR, var_n, var_v, flag_mall);
		tmp->next = NULL;
		if (flag_mall == NY_MALL || flag_mall == YES_MALL)
		{
			if (flag_mall == YES_MALL)
				free(var_n);
			free(var_v);
		}
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_var;
	new_var->var_n = ft_strdup(var_n);
	new_var->var_v = ft_strdup(var_v);
	if (!new_var->var_n || !new_var->var_v)
		env_fail(MALL_ERROR, var_n, var_v, flag_mall);
	new_var->next = NULL;
	if (flag_mall == NY_MALL || flag_mall == YES_MALL)
	{
		if (flag_mall == YES_MALL)
			free(var_n);
		free(var_v);
	}
}
