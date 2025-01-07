
#include "minishell.h"

/* void	free_env(void)
{
	t_env	*temp;
	t_env	*temp2;

	temp = my_env();
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

    if (my_env()->var_n)
        free(my_env()->var_n);
    if (my_env()->var_v)
        free(my_env()->var_v);
    temp = my_env()->next; // Start from the node after 'data'
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
    my_env()->next = NULL; // Reset the list
}

void	exit_minishell(int flag)
{
	free_env();
	if (ms()->line)
		free(ms()->line);
	exit(flag);
}

void	error_mag(int flag)
{
	if (flag == MALL_ERROR)
		ft_printf("MALLOC failed........");
	exit_minishell(flag);
}
