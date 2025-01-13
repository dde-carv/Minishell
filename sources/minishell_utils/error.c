
#include "minishell.h"

/* void	free_env(void)
{
	t_env	*temp;
	t_env	*temp2;

	temp = minishell()->my_env;
	while (temp)
	{
		temp2 = temp;
		temp = temp->next;
		if (temp2->var_n)
			free(temp2->var_n);
		if (temp2->var_v)
			free(temp2->var_v);
	}
} */

// src/minishell_utils/error.c
void	free_env(void)
{
    t_env	*temp;
    t_env	*temp2;

    if (minishell()->my_env->var_n)
        free(minishell()->my_env->var_n);
    if (minishell()->my_env->var_v)
        free(minishell()->my_env->var_v);
    temp = minishell()->my_env->next; // Start from the node after 'data'
    while (temp)
    {
        temp2 = temp;
        temp = temp->next;
        if (temp2->var_n)
            free(temp2->var_n);
        if (temp2->var_v)
            free(temp2->var_v);
        free(temp2); // Now safe, since these nodes are dynamically allocated
    }
    minishell()->my_env->next = NULL; // Reset the list
}

void	exit_minishell(int flag)
{
	free_env();
	if (minishell()->ms->line)
		free(minishell()->ms->line);
	if (minishell()->my_env)
		free(minishell()->my_env);
	if (minishell()->ms)
		free(minishell()->ms);
	if (minishell()->hash)
		free(minishell()->hash);
	exit(flag);
}

void	error_mag(int flag)
{
	if (flag == MALL_ERROR)
		ft_printf("MALLOC failed........");
	exit_minishell(flag);
}
